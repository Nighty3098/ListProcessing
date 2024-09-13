TEMPLATE = app
TARGET = ListAnalyzer
VERSION = 6.7

QT += widgets core sql

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dataprocessor.cpp \
    object.cpp

HEADERS += \
    mainwindow.h \
    dataprocessor.h \
    object.h

FORMS += \
    mainwindow.ui

macos {
    QMAKE_BUNDLE_DATA += MACOSX_BUNDLE_GUI_IDENTIFIER=com.example.ListAnalyzer
    QMAKE_BUNDLE_VERSION = $$VERSION
    QMAKE_BUNDLE_SHORT_VERSION_STRING = $$VERSION_MAJOR.$$VERSION_MINOR
}

win32 {
    CONFIG += windows
}

android {
    TARGET_ARCH = $$QT_ARCH
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}
