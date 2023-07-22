The following files had instances of "Ximea", probably need to work on these files
    1. make.m
    2. SLStudio.pro
    3. CameraFactory.cpp
    4. CameraTest.pro
    5. CameraXIMEA.cpp
    6. CameraXIMEA.h
    7. Camera.h

Path:
    1. /matlab
    2. /src
    3. /src/camera
    4. /src/camera
    5. /src/camera
    6. /src/camera

Hardware
    Camera:     MV-CA050-20UM   (Hikrobot)
    Projector:  DLP Light Crafter 4500

Development remark:
    - The codes assumed only 1 single Hikrobot camera is connected to the PC. (i.e. Camera[0])

Compiling procedure:
    sudo apt-get install libpcl-dev libopencv-dev libvtk9-qt-dev libglew-dev freeglut3-dev qtcreator libusb-1.0-0-dev qmake6 libxrandr-dev0-0-dev qmake6 libxrandr-dev
    git clone https://github.com/757dyar/NewTest.git
    cd slstudio
    mkdir qmake_build
    cd qmake_build
    qmake -makefile -o Makefile ../src/SLStudio.pro
    make
    ./SLStudio

Definition of Setting:
    1. Gamma
        https://www.benq.com/en-us/knowledge-center/knowledge/gamma-monitor.html#:~:text=Gamma%20can%20be%20described%20as,or%20from%20white%20to%20black.
    2. Hardware Trigger vs Software Trigger
        https://www.vision-doctor.com/en/camera-technology-basics/trigger-functions.html


22/07/2023 Progress:
    Outstanding:
        - stop capture
        - get width
        - get height
        - destructor