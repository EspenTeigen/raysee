#!/bin/bash

./clean.sh
cmake -GNinja -DTARGET_GROUP=prod ..
ninja -v