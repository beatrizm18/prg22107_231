QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    campo_minado.cpp \
    celula.cpp \
    jogador.cpp \
    main.cpp \
    mainwindow.cpp \
    minebutton.cpp \
    tabuleiro.cpp

HEADERS += \
    campo_minado.h \
    celula.h \
    jogador.h \
    mainwindow.h \
    minebutton.h \
    tabuleiro.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    CAMPOMINADOFINAL.pro

DISTFILES += \
    CAMPOMINADOFINAL.pro.user \
    Campo_Minado.pro.user
