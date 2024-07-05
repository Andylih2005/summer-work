QT       += core gui
QT       += Sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DESTDIR=$$PWD/../bin

include($$PWD/cell/cell.pri)
include($$PWD/lib/lib.pri)
