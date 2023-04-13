#include "rays.h"
#include <stdlib.h>  
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



intersections_t* rays_alloc_intersections_t(size_t number_of_elements){

   intersections_t *xs = malloc(sizeof(*xs) + number_of_elements*sizeof(intersect_t));

   if(!xs){
    printf("failed to malloc intersections_t");
    return NULL;
   }
   else{
    xs->count = number_of_elements;
    return xs;
   }  
}

void rays_ray(point4 origin, vect4 direction, ray_t *res)
{
    memcpy(res->origin, origin, sizeof(point4));
    memcpy(res->direction, direction, sizeof(vect4));
}

void rays_position(ray_t *ray, double t, point4 res)
{
    for(int i = 0; i < 4; i++){
        res[i] = ray->origin[i] + ray->direction[i] * t;
    }
}

void rays_sphere(sphere_t *shape)
{   
    srand(time(NULL));
    shape->object = SPHERE;
    shape->r = (double)rand()*0.94335;
}

void sphere_intersect(sphere_t *sphere, ray_t *ray, intersections_t *res)
{   
    //calculate discriminant
    point4 p;
    point(0.0, 0.0, 0.0, p);
    vect4 edge_to_ray;
    sub_two_tuples(ray->origin, p, edge_to_ray);

    double a = vect4_dot(ray->direction, ray->direction);
    double b = 2.0 * vect4_dot(ray->direction, edge_to_ray);
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

void rays_intersections(intersect_t *intersections, size_t n_intersects, intersections_t *xs)
{
    xs->count = n_intersects;
    for(int i = 0; i < n_intersects; i++){
        //printf("intersections t %f\n", intersections[i].t);
        xs->xs[i].t = intersections[i].t;
    }
}

void rays_hit(intersections_t *xs, intersect_t *hit)
{   

    double t0_temp = xs->xs[0].t;
    double t1_temp = xs->xs[1].t;

    if((t0_temp > t1_temp)){
        double temp = t0_temp;
        t0_temp = t1_temp;
        t1_temp = temp;
    }
    if(t1_temp < 0.0){
        hit->t = NAN;
        hit->object = 0;
    }
    else if(t0_temp < 0.0){
        hit->t = t1_temp;
        hit->object = xs->xs[0].object;
    }
    else{
        hit->t = t0_temp;
        hit->object = xs->xs[0].object;
    }
}
