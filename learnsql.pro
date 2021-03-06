QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminiadd.cpp \
    adminidel.cpp \
    adminifunc.cpp \
    adminipage.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    modifypassword.cpp \
    signinpage.cpp \
    stupage.cpp \
    teapage.cpp

HEADERS += \
    adminiadd.h \
    adminidel.h \
    adminifunc.h \
    adminipage.h \
    database.h \
    mainwindow.h \
    modifypassword.h \
    signinpage.h \
    stupage.h \
    teapage.h

FORMS += \
    adminiadd.ui \
    adminidel.ui \
    adminifunc.ui \
    adminipage.ui \
    mainwindow.ui \
    modifypassword.ui \
    signinpage.ui \
    stupage.ui \
    teapage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
