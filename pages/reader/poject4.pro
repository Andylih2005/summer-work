QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookmode.cpp \
    changebook.cpp \
    checkbook.cpp \
    findbook.cpp \
    inputbook.cpp \
    main.cpp \
    mainwindow.cpp \
    paymode.cpp \
    personal.cpp \
    usemmanagement.cpp

HEADERS += \
    bookmode.h \
    changebook.h \
    checkbook.h \
    findbook.h \
    inputbook.h \
    mainwindow.h \
    paymode.h \
    personal.h \
    usemmanagement.h

FORMS += \
    bookmode.ui \
    changebook.ui \
    checkbook.ui \
    findbook.ui \
    inputbook.ui \
    mainwindow.ui \
    paymode.ui \
    personal.ui \
    usemmanagement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_PROJECT_DEPTH=0

RESOURCES += \
    resources.qrc
