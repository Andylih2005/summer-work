QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookmode.cpp \
    findbook.cpp \
    main.cpp \
    mainwindow.cpp \
    paymode.cpp \
    personal.cpp

HEADERS += \
    bookmode.h \
    findbook.h \
    mainwindow.h \
    paymode.h \
    personal.h

FORMS += \
    bookmode.ui \
    findbook.ui \
    mainwindow.ui \
    paymode.ui \
    personal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_PROJECT_DEPTH=0

RESOURCES += \
    resources.qrc
