QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoveTriangle
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    scene.cpp \
    triangle.cpp

HEADERS  += dialog.h \
    scene.h \
    triangle.h

FORMS    += dialog.ui

RESOURCES += \
    Shaders.qrc
