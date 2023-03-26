#!/bin/bash

./clean.sh
cmake -GNinja -DTARGET_GROUP=test ..
ninja -v
