TEMPLATE = app
CONFIG += console c++19
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bullet.cpp \
        button.cpp \
        deathstar.cpp \
        main.cpp \
        normalshot.cpp \
        opponents.cpp \
        player.cpp \
        protonbomb.cpp \
        tiefighter.cpp

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    bullet.h \
    button.h \
    deathstar.h \
    normalshot.h \
    opponents.h \
    player.h \
    protonbomb.h \
    tiefighter.h
