#include "spheres.h"
#include <string.h>

sphere_t sphere()
{   
    sphere_t s;
    s.r = 1;
    s.object = SPHERE;
    matrix4_get_identity(s.transform);
    return s;
}

void sphere_set_transform(sphere_t *sphere, matrix4 transform)
{
    matrix4 temp;
    matrix4_mult(transform, sphere->transform, temp);
    memcpy(sphere->transform, temp, sizeof(matrix4));
}
