QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    class.cpp \
    enterentrywindow.cpp \
    entereventwindow.cpp \
    enternotewindow.cpp \
    entertaskwindow.cpp \
    errorwindow.cpp \
    function.cpp \
    main.cpp \
    mainwindow.cpp \
    objects.cpp

HEADERS += \
    class.h \
    enterentrywindow.h \
    entereventwindow.h \
    enternotewindow.h \
    entertaskwindow.h \
    errorwindow.h \
    function.h \
    mainwindow.h \
    objects.h \
    struct.h

FORMS += \
    enterentrywindow.ui \
    entereventwindow.ui \
    enternotewindow.ui \
    entertaskwindow.ui \
    errorwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
