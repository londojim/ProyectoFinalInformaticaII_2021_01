QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AmigoD.cpp \
    Asignaturas.cpp \
    Boton.cpp \
    Distractor.cpp \
    Drogas.cpp \
    Game.cpp \
    Jugador.cpp \
    Puntaje.cpp \
    main.cpp \
    profesor.cpp \
    vreto.cpp

HEADERS += \
    AmigoD.h \
    Asignaturas.h \
    Boton.h \
    Distractor.h \
    Drogas.h \
    Game.h \
    Jugador.h \
    Puntaje.h \
    profesor.h \
    vreto.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    S.qrc

FORMS += \
    dialog.ui
