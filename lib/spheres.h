#ifndef SPHERES_H_
#define SPHERES_H_

#include <tuples.h>
#include <matrices.h>

typedef enum{
    SPHERE = 1
}objects_t;

typedef struct{
    double r;
    matrix4 transform;
    objects_t object;
}sphere_t;

#endif

sphere_t sphere();

void sphere_set_transform(sphere_t *sphere, matrix4 transform);