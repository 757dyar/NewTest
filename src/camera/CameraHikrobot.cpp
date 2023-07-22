#include "CameraHikrobot.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstdio>

// Note: library headers conflict with IDS imaging headers
//#include <xiApi.h>



#define HandleResult(res,place) if (res!=XI_OK) {printf("CameraHikrobot: Error at %s (%d)\n",place,res); fflush(stdout);}


//To be improved:
//1. the WorkThread function was originally a static void* global function within the camerahikro,
//   but now it is changed to a member function declared in camhikro.h
//   this has 2 drawbacks: 
//      - it was not set to private.  Any object of this class can access this function and causes unexpected behaviour
//      - need to add "this->" during the calling of this function

// void* CameraHikrobot::WorkThread(void* pUser) //the workthread function is placed directly here to avoid typo
// {
//     int nRetWT = MV_OK;
//     MV_FRAME_OUT stOutFrame = {0};
//     memset(&stOutFrame, 0, sizeof(MV_FRAME_OUT));
//     while(1)
//     {
//         nRetWT = MV_CC_GetImageBuffer(pUser, &stOutFrame, 1000);
//         if (nRetWT == MV_OK)
//         {
//             printf("Get One Frame: Width[%d], Height[%d], nFrameNum[%d]\n",
//                 stOutFrame.stFrameInfo.nWidth, stOutFrame.stFrameInfo.nHeight, stOutFrame.stFrameInfo.nFrameNum);
//         }
//         else
//         {
//             printf("No data[0x%x]\n", nRetWT);
//         }
//         if(NULL != stOutFrame.pBufAddr)
//         {
//             nRetWT = MV_CC_FreeImageBuffer(pUser, &stOutFrame);
//             if(nRetWT != MV_OK)
//             {
//                 printf("Free Image Buffer fail! nRetWT [0x%x]\n", nRetWT);
//             }
//         }
//         if(g_bExit)
//         {
//             break;
//         }
//     }
//     return 0;
// }

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

// static void* WorkThread(void* pUser)
// {
//     int nRet = MV_OK;
//     // ch:获取数据包大小 | en:Get payload size
//     MVCC_INTVALUE stParam;
//     memset(&stParam, 0, sizeof(MVCC_INTVALUE));
//     nRet = MV_CC_GetIntValue(pUser, "PayloadSize", &stParam);
//     if (MV_OK != nRet)
//     {
//         printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
//         return NULL;
//     }
//     MV_FRAME_OUT_INFO_EX stImageInfo = {0};
//     memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
//     unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * stParam.nCurValue);
//     if (NULL == pData)
//     {
//         return NULL;
//     }
//     unsigned int nDataSize = stParam.nCurValue;
//     while(1)
//     {
// 		if(g_bExit)
// 		{
// 			break;
// 		}
//         nRet = MV_CC_GetOneFrameTimeout(pUser, pData, nDataSize, &stImageInfo, 1000);
//         if (nRet == MV_OK)
//         {
//             printf("GetOneFrame, Width[%d], Height[%d], nFrameNum[%d]\n", 
//                 stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
//         }
//         else{
//             printf("No data[%x]\n", nRet);
//         }
//     }
//     free(pData);
//     return 0;
// }

std::vector<CameraInfo> CameraHikrobot::getCameraList(){

    MV_CC_DEVICE_INFO_LIST stDeviceList;
    unsigned int numCams = stDeviceList.nDeviceNum;
    memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
    //nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
    std::vector<CameraInfo> ret(numCams);

    for(unsigned int i = 0; i < numCams; i++) {
        //MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[i];
        CameraInfo info;
        info.vendor = "Hikrobot";
        info.model = "Hikrobot";
        info.busID = i;
        ret[i] = info;
    }
    return ret;
}

CameraHikrobot::CameraHikrobot(unsigned int camNum, CameraTriggerMode triggerMode)
    : Camera(triggerMode), 
    camera(NULL), //this is the variable copied from Ximea camera
    g_bExit{ false }, 
    g_nPayloadSize{ 0 }, 
    nRet{ MV_OK }, 
    handle{ NULL }
    
    {
    do
    {
        MV_CC_DEVICE_INFO_LIST stDeviceList;
        memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
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
    nRet = MV_CC_GetFloatValue(handle, "Gain", &stGain);

    settings.shutter = stExposureTime.fCurValue / 1000.0;
    settings.gain = stGain.fCurValue;

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

}

void CameraHikrobot::startCapture(){

    // ch:开始取流 | en:Start grab image
    nRet = MV_CC_StartGrabbing(handle);
    if (MV_OK != nRet)
    {
        printf("Start Grabbing fail! nRet [0x%x]\n", nRet);
    }
}

void CameraHikrobot::stopCapture(){

    if(!capturing){
        std::cerr << "CameraHikrobot: not capturing!" << std::endl;
        return;
    }

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

    free(pData);

    // Create single image buffer
    XI_IMG image;
    image.size = sizeof(XI_IMG); // must be initialized
    //image.bp = NULL;
    //image.bp_size = 0;

    if(triggerMode == triggerModeSoftware){
        // Fire software trigger
        stat = xiSetParamInt(camera, XI_PRM_TRG_SOFTWARE, 0);
        HandleResult(stat,"xiSetParam (XI_PRM_TRG_SOFTWARE)");

        // Retrieve image from camera
        stat = xiGetImage(camera, 1000, &image);
        HandleResult(stat,"xiGetImage");
    } else {

        // Retrieve image from camera
        stat = xiGetImage(camera, 1000, &image);
        HandleResult(stat,"xiGetImage");
    }

//    // Empty buffer
//    while(xiGetImage(camera, 1, &image) == XI_OK){
//        std::cerr << "drop!" << std::endl;
//        continue;
//    }

    //std::cout << image.exposure_time_us  << std::endl << std::flush;
    //std::cout << image.exposure_sub_times_us[3]  << std::endl << std::flush;
    //std::cout << image.GPI_level  << std::endl << std::flush;

    CameraFrame frame;
    frame.height = image.height;
    frame.width = image.width;
    frame.memory = (unsigned char*)image.bp;
    frame.timeStamp = image.tsUSec;
    frame.sizeBytes = image.bp_size;
    frame.flags = image.GPI_level;

    return frame;
}


size_t CameraHikrobot::getFrameSizeBytes(){
    return 0;
}

size_t CameraHikrobot::getFrameWidth(){
    int w;
    xiGetParamInt(camera, XI_PRM_WIDTH, &w);

    return w;
}

size_t CameraHikrobot::getFrameHeight(){
    int h;
    xiGetParamInt(camera, XI_PRM_HEIGHT, &h);

    return h;
}

CameraHikrobot::~CameraHikrobot(){

    if(capturing){
        // Stop acquisition
        stat = xiStopAcquisition(camera);
        HandleResult(stat,"xiStopAcquisition");
    }

    // Close device
    xiCloseDevice(camera);
}


