#!/bin/bash

MODULES="xstring bitree id"

SOURCES=""
OBJECTS=""

for m in $MODULES; do
    SOURCES="$m.cpp $SOURCES"
    OBJECTS="$m.o $OBJECTS"
done

g++ -std=c++11 -shared -fPIC -o libmustard.so $SOURCES

#LIB_NAME=libmustard.a
#ar ruv $LIB_NAME *.o
