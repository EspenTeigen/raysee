#include "tuples.h"
#include <math.h>
#include <inttypes.h>


// Used to check if two doubles is equal enough
bool epsilon_equal(double a, double b)
{
    if (fabs((double)a - (double)b) < EPSILON)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tuple(double x, double y, double z, double w, vect4 res)
{
    res[X] = x;
    res[Y] = y;
    res[Z] = z;
    res[W] = w;
}


void point(double x, double y, double z, vect4 res)
{
    res[X] = x;
    res[Y] = y;
    res[Z] = z;
    res[W] = 1.0;
}


void vector(double x, double y, double z, vect4 res)
{
    res[X] = x;
    res[Y] = y;
    res[Z] = z;
    res[W] = 0.0;
}


bool tuple_equal(vect4 a, vect4 b)
{

    if (epsilon_equal(a[X], b[X]) &&
        epsilon_equal(a[Y], b[Y]) &&
        epsilon_equal(a[Z], b[Z]) &&
        epsilon_equal(a[W], b[W]))
    {

        return true;
    }
    else
    {
        return false;
    }
}


void add_tuple(vect4 a, vect4 b, vect4 res)
{
        res[X] = a[X] + b[X];
        res[Y] = a[Y] + b[Y];
        res[Z] = a[Z] + b[Z];
        res[W] = a[W] + b[W];
}


void sub_two_tuples(vect4 a, vect4 b, vect4 res)
{
        res[X] = a[X] - b[X],
        res[Y] = a[Y] - b[Y],
        res[Z] = a[Z] - b[Z],
        res[W] = a[W] - b[W];
}

void negate(vect4 a, vect4 res)
{
    res[X] = -1.0f * a[X];
    res[Y] = -1.0f * a[Y];
    res[Z] = -1.0f * a[Z];
    res[W] = -1.0f * a[W];
}

void scalar_mult(double scalar, vect4 b, vect4 res)
{
    res[X] = b[X] * scalar;
    res[Y] = b[Y] * scalar;
    res[Z] = b[Z] * scalar;
    res[W] = b[W] * scalar;
}

void scalar_div(double scalar, vect4 b, vect4 res)
{
    res[X] = b[X] / scalar;
    res[Y] = b[Y] / scalar;
    res[Z] = b[Z] / scalar;
    res[W] = b[W] / scalar;
}

double mag(vect4 a)
{
    return sqrt(pow(a[X], 2.0) + pow(a[Y], 2.0) + pow(a[Z], 2.0) + pow(a[W], 2.0));
}

void norm(vect4 a, vect4 res)
{
   
    for(int i = 0; i < 4; i++){

        double mag_calc = mag(a);

        if(epsilon_equal(a[i], 0.0) == true){
            res[i] = 0;
        }
        else{
            res[i] = a[i] / mag_calc;
        }
    }
}

// Takes two vectors, return dot product
double dot_p(vect4 a, vect4 b)
{
    return (a[X] * b[X]) + (a[Y] * b[Y]) + (a[Z] * b[Z]) + (a[W] * b[W]);
}

void cross_p(vect4 a, vect4 b, vect4 res){
    res[X] = (a[Y] * b[Z]) - (a[Z] * b[Y]);
    res[Y] = (a[Z] * b[X]) - (a[X] * b[Z]);   
    res[Z] = (a[X] * b[Y]) - (a[Y] * b[X]);
    res[W] = 0.0;
}

bool is_vector(vect4 v)
{
    return epsilon_equal(0.0f, v[W]);
}

bool is_point(vect4 p)
{
    return epsilon_equal(1.0, p[W]);
}

//------------ Colors-------------------

void color_create(double r, double g, double b, color_t *res){

    res->r = r;
    res->g = g;
    res->b = b;
}

void color_add(color_t *c1, color_t *c2, color_t *res){
   
    res->r = c1->r + c2->r;
    res->g = c1->g + c2->g;
    res->b = c1->b + c2->b;
}

void color_sub(color_t *c1, color_t *c2, color_t *res){
 
    res->r = c1->r - c2->r;
    res->g = c1->g - c2->g;
    res->b = c1->b - c2->b;
}

void color_scalar_mult(double scalar, color_t *c, color_t *res){

    res->r = c->r * scalar;
    res->g = c->g * scalar;
    res->b = c->b * scalar;
}

void color_mult(color_t *c1, color_t *c2, color_t *res){
  
    res->r = c1->r * c2->r;
    res->g = c1->g * c2->g;
    res->b = c1->b * c2->b;
}
