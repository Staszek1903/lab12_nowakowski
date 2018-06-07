TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ctablica.cpp \
    csorttablica.cpp \
    menu.cpp \
    input.cpp \
    additivgenerator.cpp \
    lineargenerator.cpp \
    shufflinggenerator.cpp \
    file.cpp \
    fileexception.cpp \
    inputexception.cpp

HEADERS += \
    ctablica.h \
    csorttablica.h \
    menu.h \
    input.h \
    additivgenerator.h \
    lineargenerator.h \
    shufflinggenerator.h \
    file.h \
    fileexception.h \
    inputexception.h
