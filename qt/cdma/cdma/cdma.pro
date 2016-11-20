#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T22:17:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#在windows下使用第三方库的方法
LIBS += -LD:\yourmysql\lib -llibmysql
#在linux下使用第三方库的方法
# LIBS += -lmysqlclient
TARGET = cdma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    scriptdlg.cpp \
    yourmysql.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    scriptdlg.h \
    yourmysql.h
