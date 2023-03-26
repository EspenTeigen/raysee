#!/bin/bash

cmake -GNinja -DTARGET_GROUP=prod ..
ninja -v
cd main
./main