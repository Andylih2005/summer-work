QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book_window.cpp \
    find_window.cpp \
    main.cpp \
    personal_window.cpp

HEADERS += \
    book_window.h \
    find_window.h \
    personal_window.h

FORMS += \
    book_window.ui \
    find_window.ui \
    personal_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_PROJECT_DEPTH=0

RESOURCES += \
    resources.qrc
