#include "CameraHikrobot.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstdio>

// Note: library headers conflict with IDS imaging headers
//#include <xiApi.h>
#include <MvCameraControl.h>


#define HandleResult(res,place) if (res!=XI_OK) {printf("CameraHikrobot: Error at %s (%d)\n",place,res); fflush(stdout);}

static  void* WorkThread(void* pUser) //the workthread function is placed directly here to avoid typo
{
    int nRet = MV_OK;

    MV_FRAME_OUT stOutFrame = {0};
    memset(&stOutFrame, 0, sizeof(MV_FRAME_OUT));

    while(1)
    {
        nRet = MV_CC_GetImageBuffer(pUser, &stOutFrame, 1000);
        if (nRet == MV_OK)
        {
            printf("Get One Frame: Width[%d], Height[%d], nFrameNum[%d]\n",
                stOutFrame.stFrameInfo.nWidth, stOutFrame.stFrameInfo.nHeight, stOutFrame.stFrameInfo.nFrameNum);
        }
        else
        {
            printf("No data[0x%x]\n", nRet);
        }
        if(NULL != stOutFrame.pBufAddr)
        {
            nRet = MV_CC_FreeImageBuffer(pUser, &stOutFrame);
            if(nRet != MV_OK)
            {
                printf("Free Image Buffer fail! nRet [0x%x]\n", nRet);
            }
        }
        if(g_bExit)
        {
            break;
        }
    }

    return 0;
}

std::vector<CameraInfo> CameraHikrobot::getCameraList(){

    XI_RETURN stat = XI_OK;
    DWORD numCams;
    stat = xiGetNumberDevices(&numCams);
    HandleResult(stat, "xiGetNumberDevices");

    std::vector<CameraInfo> ret(numCams);
    for(unsigned int i=0; i<numCams; i++){
        CameraInfo info;
        info.vendor = "Ximea";
        char name[20];
        xiGetDeviceInfoString(i, XI_PRM_DEVICE_NAME, name, 20);
        info.model = name;
        info.busID = i;
        ret[i] = info;
    }
    return ret;
}

CameraHikrobot::CameraHikrobot(unsigned int camNum, CameraTriggerMode triggerMode)
    : Camera(triggerMode), 
    camera(NULL), 
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
                {   //this is PrintDeviceInfo function in sample code.
                    if (NULL == pDeviceInfo)
                    {
                        printf("The Pointer of pDeviceInfo is NULL!\n");
                        //return false; (avoid returning in constructor)
                    }
                    if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
                    {
                        int nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
                        int nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
                        int nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
                        int nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

                        // ch:打印当前相机ip和用户自定义名字 | en:print current ip and user defined name
                        printf("CurrentIp: %d.%d.%d.%d\n" , nIp1, nIp2, nIp3, nIp4);
                        printf("UserDefinedName: %s\n\n" , pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName);
                    }
                    else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
                    {
                        printf("UserDefinedName: %s\n", pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName);
                        printf("Serial Number: %s\n", pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);
                        printf("Device Number: %d\n\n", pDeviceInfo->SpecialInfo.stUsb3VInfo.nDeviceNumber);
                    }
                    else
                    {
                        printf("Not support.\n");
                    }
                }         
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
        MV_CC_SetBoolValue(handle, "GammaEnable", 1);   //Enable Gamma
        MV_CC_SetEnumValue(handle, "GammaSelector", 1); //Enable User defined Gamma
        MV_CC_SetFloatValue(handle, "Gamma", 1.f); //Input Gamma value

        //Set Exposure
        MV_CC_SetEnumValue(handle, "ExposureAuto", 0);
        MV_CC_SetEnumValue(handle, "ExposureMode", 0);
        MV_CC_SetFloatValue(handle, "ExposureTime", 16666.f);

        MV_CC_SetEnumValue(handle, "PixelFormat", 0x01080001);

        //MV_CC_SetIntValueEx ,
        //MV_CC_SetEnumValue , MV_CC_SetFloatValue , MV_CC_SetBoolValue ,
        //MV_CC_SetStringValue , MV_CC_SetCommandValue

    }
    while (0);

}

CameraSettings CameraHikrobot::getCameraSettings(){

    CameraSettings settings;

    int shutter;
    xiGetParamInt(camera, XI_PRM_EXPOSURE, &shutter);
    settings.shutter = shutter/1000.0; // from us to ms
    xiGetParamFloat(camera, XI_PRM_GAIN, &settings.gain);

    return settings;
}

void CameraHikrobot::setCameraSettings(CameraSettings settings){

    // Set shutter (in us)
    xiSetParamInt(camera, XI_PRM_EXPOSURE, settings.shutter*1000);
    // Set gain (in dB)
    xiSetParamFloat(camera, XI_PRM_GAIN, settings.gain);

    std::cout << "Setting camera parameters:" << std::endl
              << "Shutter: " << settings.shutter << " ms" << std::endl
              << "Gain: " << settings.gain << " dB" << std::endl;
}

void CameraHikrobot::startCapture(){

    if(triggerMode == triggerModeHardware){
        xiSetParamInt(camera, XI_PRM_ACQ_TIMING_MODE, XI_ACQ_TIMING_MODE_FREE_RUN);

        // Configure for hardware trigger
        stat = xiSetParamInt(camera, XI_PRM_TRG_SOURCE, XI_TRG_EDGE_RISING);
        HandleResult(stat,"xiSetParam (XI_PRM_TRG_SOURCE)");

        // Configure for exposure active trigger
        stat = xiSetParamInt(camera, XI_PRM_TRG_SELECTOR, XI_TRG_SEL_FRAME_START);
        HandleResult(stat,"xiSetParam (XI_PRM_TRG_SELECTOR)");

    } else if(triggerMode == triggerModeSoftware){
        // Configure for software trigger (for getSingleFrame())
        stat = xiSetParamInt(camera, XI_PRM_TRG_SOURCE, XI_TRG_SOFTWARE);
        HandleResult(stat,"xiSetParam (XI_PRM_TRG_SOURCE)");
    }

    // Start aquistion
    stat = xiStartAcquisition(camera);
    HandleResult(stat,"xiStartAcquisition");

    capturing = true;

}

void CameraHikrobot::stopCapture(){

    if(!capturing){
        std::cerr << "CameraHikrobot: not capturing!" << std::endl;
        return;
    }

}

CameraFrame CameraHikrobot::getFrame(){

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


