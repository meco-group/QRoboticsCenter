#!/bin/bash
rm -rf build/ && mkdir build && cd build
qmake ../src/QRoboticsCenter/QRoboticsCenter.pro
make -j5
cd ..
