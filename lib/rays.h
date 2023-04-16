#ifndef RAYS_H_
#define RAYS_H_

#include <tuples.h>
#include <matrices.h>
#include <spheres.h>
#include <stddef.h>


typedef struct{
    point4 origin;
    vect4 direction;
} ray_t;

typedef struct{
    double t;
    objects_t object;
}intersect_t;

typedef struct{
    int count;
    intersect_t xs[];
}intersections_t;

typedef struct{
    double t;
    objects_t object;
}hit_t;

intersections_t *rays_alloc_intersections_t(size_t number_of_elements);

ray_t ray(point4 origin, vect4 direction);

void rays_position(ray_t *ray, double t, point4 res);

void rays_sphere(sphere_t *shape);

void sphere_intersect(sphere_t *sphere, ray_t *ray, intersections_t *res);

void rays_intersection(double a, sphere_t *shape, intersect_t *intersection);

void rays_intersections(intersect_t intersections[], size_t n_intersects, intersections_t *xs);

void rays_hit(intersections_t *xs, intersect_t *hit);

void rays_transform(ray_t *ray, matrix4 transform, ray_t *transformed_ray);

#endif
