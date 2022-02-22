QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custom.cpp \
    encryption.cpp \
    hash.cpp \
    main.cpp \
    mainwindow.cpp \
    training.cpp

HEADERS += \
    custom.h \
    encryption.h \
    hash.h \
    mainwindow.h \
    training.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    Books/lol.txt \
    Books/texts.txt \
    Books/Новый текстовый документ.txt \
    Texts/1.txt.txt \
    Texts/1.txt.txt.txt \
    Texts/2.txt \
    Texts/3.txt \
    Texts/4.txt \
    Texts/5.txt \
    Texts/6.txt \
    Texts/UTF-8.txt \
    Texts/neeeee.txt.txt \
    Texts/unicod.txt
