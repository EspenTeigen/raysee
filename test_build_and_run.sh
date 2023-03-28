#!/bin/bash

./clean.sh
cd build
cmake -GNinja -DTARGET_GROUP=test ..
ninja -v
ctest --verbose