#!/bin/bash

g++ -c *.cpp

LIB_NAME=libmustard.a
ar ruv $LIB_NAME *.o
