#!/usr/bin/env bash

rm -rf build
mkdir build
cd build
cmake ../ -DCMAKE_C_COMPILER=afl-cc
make
afl-fuzz -V 1 -i ../tests/cases/afl -o ../analysis ./axolotl
