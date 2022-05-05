QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0




INCLUDEPATH += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\include


LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_calib3d455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_core455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_dnn455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_features2d455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_flann455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_gapi455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_highgui455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_imgcodecs455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_imgproc455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_ml455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_objdetect455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_photo455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_stitching455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_video455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\libopencv_videoio455.dll
LIBS += C:\Users\Intrigger\Downloads\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\bin\opencv_videoio_ffmpeg455_64.dll



SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
