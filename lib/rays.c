#include "rays.h"
#include <stdlib.h>  
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


static int sort_compare(const void *a, const void *b){
    intersect_t *intersectA = (intersect_t *)a;
    intersect_t *intersectB = (intersect_t *)b;

    return intersectA->t - intersectB->t;
}

intersections_t* rays_alloc_intersections_t(size_t number_of_elements){

   intersections_t *xs = calloc(number_of_elements, sizeof(xs) + number_of_elements*sizeof(intersect_t));

   if(!xs){
    printf("failed to malloc intersections_t");
    return NULL;
   }
   else{
    xs->count = number_of_elements;
    return xs;
   }  
}

ray_t ray(point4 origin, vect4 direction)
{
    ray_t res;
    memcpy(res.origin, origin, sizeof(point4));
    memcpy(res.direction, direction, sizeof(vect4));
    return res;
}

void rays_position(ray_t *ray, double t, point4 res)
{
    for(int i = 0; i < 4; i++){
        res[i] = ray->origin[i] + ray->direction[i] * t;
    }
}



void sphere_intersect(sphere_t *sphere, ray_t *ray, intersections_t *res)
{   
    matrix4 sphere_inv ;
    matrix4_inverse(sphere->transform, sphere_inv);
   
    ray_t ray_inv;
    rays_transform(ray, sphere_inv, &ray_inv);
    
  //  for(int i = 0; i < 4; i++){
  //      printf("normal %f \n", ray->direction[i]);
  //  }
  //  for(int i = 0; i < 4; i++){
  //      printf("inverted %f \n", ray_inv.direction[i]);
  //  }

    //calculate discriminant
    point4 p;
    point(0.0, 0.0, 0.0, p);
    vect4 edge_to_ray;
    sub_two_tuples(ray_inv.origin, p, edge_to_ray);

    double a = vect4_dot(ray_inv.direction, ray_inv.direction);
    double b = 2.0 * vect4_dot(ray_inv.direction, edge_to_ray);
    double c = vect4_dot(edge_to_ray, edge_to_ray) - 1.0;

    double disciminant = pow(b, 2) - (4.0 * a * c);

    if(disciminant < 0.0){
        res->count = 0;
        res->xs[0].t = NAN;
        res->xs[1].t = NAN;
    }  
    else{
        res->count = 2;
        res->xs[0].t = (-b-sqrt(disciminant)) / (2*a);
        res->xs[1].t = (-b+sqrt(disciminant)) / (2*a);
        res->xs[0].object = SPHERE;
        res->xs[1].object = SPHERE;
    }
}

void rays_intersection(double a, sphere_t *shape, intersect_t *intersection)
{
    intersection->t = a;
    intersection->object = shape->object;
}

void rays_intersections(intersect_t intersections[], size_t n_intersects, intersections_t *xs)
{
    xs->count = n_intersects;
    qsort(intersections, n_intersects, sizeof(intersect_t), sort_compare);
    memcpy(xs->xs, intersections, n_intersects*sizeof(intersect_t));
}

void rays_hit(intersections_t *xs, intersect_t *hit)
{   
    bool positive_found = false;
    for(int i = 0; i < xs->count; i++){
        if(xs->xs[i].t > 0.0){
            hit->t = xs->xs[i].t;
            hit->object = xs->xs[i].object;
            positive_found = true;
            break;
        }
    }

    if(!positive_found){
        hit->t = NAN;
        hit->object = 0;
    }
}

void rays_transform(ray_t *ray, matrix4 transform, ray_t *transformed_ray)
{   
    matrix4_vect3_mult(transform, ray->origin, transformed_ray->origin);
    matrix4_vect3_mult(transform, ray->direction, transformed_ray->direction);
}

