#!/bin/bash

rm -r build
mkdir build
cd build

cmake -G "Unix Makefiles" -DTEST=true -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
