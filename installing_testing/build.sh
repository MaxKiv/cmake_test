#!/bin/bash
[ ! -d "build" ] && mkdir build
cmake -S . -B ./build
cd build
make