TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Generator/subset.cpp \
    Generator/combination.cpp \
    Generator/permutation.cpp \
    Generator/Task/knapsack_s.cpp \
    Generator/Task/boat.cpp \
    Generator/Task/salesman.cpp \
    Generator/accomodation.cpp

HEADERS += \
    Generator/subset.h \
    Generator/combination.h \
    Generator/permutation.h \
    Generator/Task/knapsack_s.h \
    Generator/Task/boat.h \
    Generator/Task/salesman.h \
    Generator/accomodation.h
