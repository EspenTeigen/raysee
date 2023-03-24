#include "tuples.h"
#include <stdio.h>

vect3 tuple(float x, float y, float z, float w){
    vect3 v = {
        .x = x,
        .y = y,
        .z = z,
        .w = w
    };
    return v;
}

vect3 point(float x, float y, float z){
    vect3 v = {
        .x = x,
        .y = y,
        .z = z,
        .w = 1.0
    };
    return v;
}

vect3 vector(float x, float y, float z){
    vect3 v = {
        .x = x,
        .y = y,
        .z = z,
        .w = 0.0
    };
    return v;
}
