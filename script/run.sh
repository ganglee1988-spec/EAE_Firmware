#!/bin/bash

mkdir -p build
cd build
cmake ..
cd ..
make
./cooling_app