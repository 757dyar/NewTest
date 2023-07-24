#include "CameraHikrobot.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstdio>

#include <MvCameraControl.h>

bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo)
{
    if (NULL == pstMVDevInfo)
    {
        printf("The Pointer of pstMVDevInfo is NULL!\n");
        return false;
    }
    if (pstMVDevInfo->nTLayerType == MV_GIGE_DEVICE)
    {
        int nIp1 = ((pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
        int nIp2 = ((pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
        int nIp3 = ((pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
        int nIp4 = (pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

        // ch:打印当前相机ip和用户自定义名字 | en:print current ip and user defined name
        printf("CurrentIp: %d.%d.%d.%d\n" , nIp1, nIp2, nIp3, nIp4);
        printf("UserDefinedName: %s\n\n" , pstMVDevInfo->SpecialInfo.stGigEInfo.chUserDefinedName);
    }
    else if (pstMVDevInfo->nTLayerType == MV_USB_DEVICE)
    {
        printf("UserDefinedName: %s\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName);
        printf("Serial Number: %s\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);
        printf("Device Number: %d\n\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.nDeviceNumber);
    }
    else
    {
        printf("Not support.\n");
    }

    return true;
}

std::vector<CameraInfo> CameraHikrobot::getCameraList(){

    //MV_CC_DEVICE_INFO_LIST stDeviceList;
    //unsigned int numCams = stDeviceList.nDeviceNum;
    //memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
    //nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);

    //printf("camnum: %u\n", numCams);

    std::vector<CameraInfo> ret(1);

    ret[0].vendor = "Hikrobot";
    ret[0].model = "MV-CA050-20UM";
    // for(unsigned int i = 0; i < numCams; i++) {
    //     //MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[i];
    //     CameraInfo info;
    //     info.vendor = "Hikrobot";
    //     info.model = "Hikrobot";
    //     info.busID = i;
    //     ret[i] = info;
    // }


    return ret;
}

CameraHikrobot::CameraHikrobot(unsigned int camNum, CameraTriggerMode triggerMode)
    : Camera(triggerMode),
    g_bExit{ false }, 
    g_nPayloadSize{ 0 }, 
    nRet{ MV_OK }, 
    handle{ NULL }
    
    {
    do
    {
        MV_CC_DEVICE_INFO_LIST stDeviceList;
        //memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
        nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);

        //Check if any Hikrobot camera is successfully connected
        if (MV_OK != nRet)
        {
            printf("Enum Devices fail! nRet [0x%x]\n", nRet);
            break;
        }

        //Check number of Hikrobot camera connected to computer
        if (stDeviceList.nDeviceNum > 0)
        {
            for (unsigned int i = 0; i < stDeviceList.nDeviceNum; i++)
            {
                printf("[device %d]:\n", i);
                MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[i];
                if (NULL == pDeviceInfo)
                {
                    break;
                } 
                PrintDeviceInfo(pDeviceInfo);            
            }  
        } 
        else
        {
            printf("Find No Devices!\n");
            break;
        }

        //Let user select the camera to be used. Camera 0 is compulsarily selected here
        //printf("Please Intput camera index:");
        unsigned int nIndex = 0;
        //scanf("%d", &nIndex);

        if (nIndex >= stDeviceList.nDeviceNum)
        {
            printf("Intput error!\n");
            break;
        }

        // ch:选择设备并创建句柄 | en:Select device and create handle
        nRet = MV_CC_CreateHandle(&handle, stDeviceList.pDeviceInfo[nIndex]);
        if (MV_OK != nRet)
        {
            printf("Create Handle fail! nRet [0x%x]\n", nRet);
            break;
        }

        // ch:打开设备 | en:Open device
        nRet = MV_CC_OpenDevice(handle);
        if (MV_OK != nRet)
        {
            printf("Open Device fail! nRet [0x%x]\n", nRet);
            break;
        }

        // ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
        if (stDeviceList.pDeviceInfo[nIndex]->nTLayerType == MV_GIGE_DEVICE)
        {
            int nPacketSize = MV_CC_GetOptimalPacketSize(handle);
            if (nPacketSize > 0)
            {
                nRet = MV_CC_SetIntValue(handle,"GevSCPSPacketSize",nPacketSize);
                if(nRet != MV_OK)
                {
                    printf("Warning: Set Packet Size fail nRet [0x%x]!\n", nRet);
                }
            }
            else
            {
                printf("Warning: Get Packet Size fail nRet [0x%x]!\n", nPacketSize);
            }
        }

        // ch:设置触发模式为off | en:Set trigger mode as off
        nRet = MV_CC_SetEnumValue(handle, "TriggerMode", 0);
        if (MV_OK != nRet)
        {
            printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
            break;
        }

        // ch:获取数据包大小 | en:Get payload size
        MVCC_INTVALUE stParam;
        memset(&stParam, 0, sizeof(MVCC_INTVALUE));
        nRet = MV_CC_GetIntValue(handle, "PayloadSize", &stParam);
        if (MV_OK != nRet)
        {
            printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
            break;
        }
        g_nPayloadSize = stParam.nCurValue;

        //Set Gamma to 1.0 (linear)
        nRet = MV_CC_SetBoolValue(handle, "GammaEnable", 1);   //Enable Gamma
        nRet = MV_CC_SetEnumValue(handle, "GammaSelector", 1); //Enable User defined Gamma
        nRet = MV_CC_SetFloatValue(handle, "Gamma", 1.f); //Input Gamma value
        if (MV_OK != nRet) {printf("Gamma Setting Fail!\n");}

        //Set Exposure
        nRet = MV_CC_SetEnumValue(handle, "ExposureAuto", 0);
        nRet = MV_CC_SetEnumValue(handle, "ExposureMode", 0);
        nRet = MV_CC_SetFloatValue(handle, "ExposureTime", 16666.f);
        if (MV_OK != nRet) {printf("Exposure Setting Fail!\n");}

        //set gain TO BE MODIFIED
        nRet = MV_CC_SetEnumValue(handle, "GainSelector", 0);
        nRet = MV_CC_SetEnumValue(handle, "GainAuto", 0);
        nRet = MV_CC_SetFloatValue(handle, "Gain", 0.f);
        if (MV_OK != nRet) {printf("Gain Setting Fail!\n");}

        //Set Pixel format
        nRet = MV_CC_SetEnumValue(handle, "PixelFormat", 0x01080001);
        if (MV_OK != nRet) {printf("Pixel Format Setting Fail!\n");}

        //MV_CC_SetIntValueEx ,
        //MV_CC_SetEnumValue , MV_CC_SetFloatValue , MV_CC_SetBoolValue ,
        //MV_CC_SetStringValue , MV_CC_SetCommandValue
        printf("constructor: %u\n", 1);
    }
    while (0);

}

CameraSettings CameraHikrobot::getCameraSettings(){

    // CameraSettings settings;

    // int shutter;
    // xiGetParamInt(camera, XI_PRM_EXPOSURE, &shutter);
    // settings.shutter = shutter/1000.0; // from us to ms
    // xiGetParamFloat(camera, XI_PRM_GAIN, &settings.gain);

    CameraSettings settings;
    MVCC_FLOATVALUE stExposureTime = {0};
    MVCC_FLOATVALUE stGain = {0};
    nRet = MV_CC_GetFloatValue(handle, "ExposureTime", &stExposureTime);
    if (MV_OK != nRet) { printf("Get Camera exposure time failed!"); }
    nRet = MV_CC_GetFloatValue(handle, "Gain", &stGain);
    if (MV_OK != nRet) { printf("Get Camera gain failed!"); }
    settings.shutter = stExposureTime.fCurValue / 1000.0;
    settings.gain = stGain.fCurValue;

    printf("getCameraSettings: %u\n", 1);

    return settings;
}

void CameraHikrobot::setCameraSettings(CameraSettings settings){

    // // Set shutter (in us)
    // xiSetParamInt(camera, XI_PRM_EXPOSURE, settings.shutter*1000);
    // // Set gain (in dB)
    // xiSetParamFloat(camera, XI_PRM_GAIN, settings.gain);

    // std::cout << "Setting camera parameters:" << std::endl
    //           << "Shutter: " << settings.shutter << " ms" << std::endl
    //           << "Gain: " << settings.gain << " dB" << std::endl;

    //Set Gamma to 1.0 (linear)
    nRet = MV_CC_SetBoolValue(handle, "GammaEnable", 1);   //Enable Gamma
    nRet = MV_CC_SetEnumValue(handle, "GammaSelector", 1); //Enable User defined Gamma
    nRet = MV_CC_SetFloatValue(handle, "Gamma", 1.f); //Input Gamma value
    if (MV_OK != nRet) {printf("Gamma Setting Fail!\n");}

    //Set Exposure
    nRet = MV_CC_SetEnumValue(handle, "ExposureAuto", 0);
    nRet = MV_CC_SetEnumValue(handle, "ExposureMode", 0);
    nRet = MV_CC_SetFloatValue(handle, "ExposureTime", settings.shutter * 1000);
    if (MV_OK != nRet) {printf("Exposure Setting Fail!\n");}

    //set gain TO BE MODIFIED
    nRet = MV_CC_SetEnumValue(handle, "GainSelector", 0);
    nRet = MV_CC_SetEnumValue(handle, "GainAuto", 0);
    nRet = MV_CC_SetFloatValue(handle, "Gain", settings.gain);
    if (MV_OK != nRet) {printf("Gain Setting Fail!\n");}

    //Set Pixel format
    nRet = MV_CC_SetEnumValue(handle, "PixelFormat", 0x01080001);
    if (MV_OK != nRet) {printf("Pixel Format Setting Fail!\n");}

    printf("setCameraSettings: %u\n", 1);

}

void CameraHikrobot::startCapture(){

    // ch:开始取流 | en:Start grab image
    nRet = MV_CC_StartGrabbing(handle);
    if (MV_OK != nRet)
    {
        printf("Start Grabbing fail! nRet [0x%x]\n", nRet);
    }
    printf("startCapture: %u\n", 1);
}

void CameraHikrobot::stopCapture(){
    nRet = MV_CC_StopGrabbing(handle);
    if (MV_OK != nRet) { printf("MV_CC_StopGrabbing fail! nRet [%x]\n", nRet); }
    printf("stopCapture: %u\n", 1);
}

CameraFrame CameraHikrobot::getFrame(){

    // ch:获取数据包大小 | en:Get payload size
    void* pUser;
    MVCC_INTVALUE stParam;
    memset(&stParam, 0, sizeof(MVCC_INTVALUE));
    nRet = MV_CC_GetIntValue(pUser, "PayloadSize", &stParam);
    if (MV_OK != nRet)
    {
        printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
        //return NULL;
    }

    MV_FRAME_OUT_INFO_EX stImageInfo = {0};
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
    unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * stParam.nCurValue);
    if (NULL == pData)
    {
        //return NULL;
    }
    unsigned int nDataSize = stParam.nCurValue;

    nRet = MV_CC_GetOneFrameTimeout(pUser, pData, nDataSize, &stImageInfo, 1000);
    if (nRet == MV_OK)
    {
        printf("GetOneFrame, Width[%d], Height[%d], nFrameNum[%d]\n", 
            stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
    }
    else{
        printf("No data[%x]\n", nRet);
    }

    CameraFrame frame;
    frame.height = stImageInfo.nHeight;
    frame.width = stImageInfo.nWidth;
    frame.memory = (unsigned char*)pData;
    frame.timeStamp = stImageInfo.nHostTimeStamp;

    //frame.sizeBytes = ;
    //frame.flags = image.GPI_level;
    printf("getFrame: %u\n", 1);
    
    free(pData);
    return frame;
}


size_t CameraHikrobot::getFrameSizeBytes(){
    return 0;
}

size_t CameraHikrobot::getFrameWidth(){
    MVCC_INTVALUE stWidth = {0};
    nRet = MV_CC_GetIntValue(handle, "Width", &stWidth);
    if (MV_OK != nRet) { printf("Get Camera frame width failed!"); }
    printf("getFrameWidth: %u\n", 1);
    return stWidth.nCurValue;
}

size_t CameraHikrobot::getFrameHeight(){
    MVCC_INTVALUE stHeight = {0};
    nRet = MV_CC_GetIntValue(handle, "Height", &stHeight);
    if (MV_OK != nRet) { printf("Get Camera frame height failed!"); }
    printf("getFrameHeight: %u\n", 1);
    return stHeight.nCurValue;
}

CameraHikrobot::~CameraHikrobot(){

    printf("destructor: %u\n", 1);

    nRet = MV_CC_CloseDevice(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_CloseDevice fail! nRet [%x]\n", nRet);
    }

    // 销毁句柄
    // destroy handle
    nRet = MV_CC_DestroyHandle(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_DestroyHandle fail! nRet [%x]\n", nRet);
    }

    if (nRet != MV_OK)
    {
        if (handle != NULL)
        {
            MV_CC_DestroyHandle(handle);
            handle = NULL;
        }
    }
}


