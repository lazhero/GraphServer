QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GraphAlgo/FloydWAlgo.cpp \
    GraphAlgo/FloydWResponse.cpp \
    localserver.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DoubleList/DoubleList.hpp \
    DoubleNode/DoubleNode.hpp \
    Graph/DirectedGraph.hpp \
    GraphAlgo/FloydWAlgo.h \
    GraphAlgo/FloydWResponse.h \
    localserver.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QMAKE_CXXFLAGS+=-std=gnu++11
