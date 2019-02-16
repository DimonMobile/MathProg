TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Generator/subset.cpp \
    Generator/combination.cpp \
    Generator/Task/knapsack_s.cpp \
    Generator/Task/boat.cpp

HEADERS += \
    Generator/subset.h \
    Generator/combination.h \
    Generator/Task/knapsack_s.h \
    Generator/Task/boat.h
