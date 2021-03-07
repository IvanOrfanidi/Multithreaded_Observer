#!/bin/bash

if [ -n "$1" ]
    then
        PARAMETER=$1
fi

mkdir -p build
cd build

cmake -G "Unix Makefiles" ${PARAMETER} ..
cmake --build . -- -j4
