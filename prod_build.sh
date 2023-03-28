#!/bin/bash

./clean.sh
cd build
cmake -GNinja -DTARGET_GROUP=prod ..
ninja -v
