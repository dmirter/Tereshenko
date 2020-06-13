include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
HEADERS += \
        ../Test/IKeypad.h \
        ../Test/ILatch.h \
        ../Test/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../Test/lockcontroller.cpp \
        main.cpp
INCLUDEPATH +=D:\Institut\Test
