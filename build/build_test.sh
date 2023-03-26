#!/bin/bash

cmake -GNinja -DTARGET_GROUP=test ..
ninja -v
