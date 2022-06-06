QT += widgets

TEMPLATE = lib
DEFINES += TEMPLATE_PLUGIN_LIBRARY

CONFIG += plugin

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../cvplugininterface

INCLUDEPATH += /user/local/include/opencv4
DEPENDPATH += /user/local/include/opencv4

LIBS+= -L"/user/local/lib" -lopencv_core  -lopencv_imgproc \
               -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio \
               -lopencv_video -lopencv_objdetect -lopencv_dnn -lopencv_features2d


SOURCES += \
    keypoint_plugin.cpp

HEADERS += \
    keypoint_plugin_global.h \
    keypoint_plugin.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    plugin.ui
