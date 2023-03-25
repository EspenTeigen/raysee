#include "tuples.h"
#include <math.h>
#define EPSILON 0.0001

static inline bool epsilon_equal(float a, float b){
    if(fabs((double)a - (double)b) < EPSILON){
        return true;
    }
    else{
        return false;
    }
}

vect3 tuple(float x, float y, float z, float w){
    vect3 v = {x, y, z, w};
    return v;
}

vect3 point(float x, float y, float z){
    vect3 v = { x, y, z, 1.0f};
    return v;
}

vect3 vector(float x, float y, float z){
    vect3 v = {x,y,z, 0.0f};
    return v;
}

bool vect_equal(vect3 *a, vect3 *b){
    
    if( epsilon_equal(a->x, b->x) &&
        epsilon_equal(a->y, b->y) &&
        epsilon_equal(a->z, b->z) &&
        epsilon_equal(a->w, b->w) ){

        return true;
    }
    else{
        return false;
    }
}

vect3 add_tuple(vect3 *a, vect3 *b){
    
    vect3 res = {
        .x = a->x + b->x,
        .y = a->y + b->y,
        .z = a->z + b->z,
        .w = a->w + b->w
    };
    return res;
}

vect3 sub_two_tuples(vect3 *a, vect3 *b){
    
    vect3 res = {
        .x = a->x - b->x,
        .y = a->y - b->y,
        .z = a->z - b->z,
        .w = a->w - b->w
    };
    return res;
}

vect3 negate(vect3 *a){
    vect3 v = {
        .x = -1.0f * a->x,
        .y = -1.0f * a->y,
        .z = -1.0f * a->z,
        .w = -1.0f * a->w
    };
    return v;
}

vect3 scalar_mult(float scalar, vect3 *b){
    vect3 v = {
        .x =  b->x * scalar,
        .y =  b->y * scalar,
        .z =  b->z * scalar,
        .w =  b->w * scalar
    };
    return v;
}

vect3 scalar_div(float scalar, vect3 *b){
    vect3 v = {
        .x = b->x / scalar,
        .y = b->y / scalar,
        .z = b->z / scalar,
        .w = b->w / scalar
    };
    return v;
}

bool is_vector(vect3 *v){
    return epsilon_equal(0.0f, v->w);
}

bool is_point(vect3 *p){
    return epsilon_equal(1.0f, p->w);
}