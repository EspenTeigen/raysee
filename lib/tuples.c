#include "tuples.h"
#include <math.h>
#include <inttypes.h>

static inline bool epsilon_equal(double a, double b)
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

static inline float inv_sqrt(float a)
{
    union
    {
        float f;
        uint32_t i;
    } conv = {.f = a};
    conv.i = 0x5f200000 - (conv.i >> 1);
    conv.f *= 1.68191391f - (a * 0.703952009f * conv.f * conv.f);
    conv.f *= 1.50000036f - (a * 0.500000053f * conv.f * conv.f);
    return conv.f;
}

vect3 tuple(float x, float y, float z, float w)
{
    vect3 v = {x, y, z, w};
    return v;
}

vect3 point(float x, float y, float z)
{
    vect3 v = {x, y, z, 1.0f};
    return v;
}

vect3 vector(float x, float y, float z)
{
    vect3 v = {x, y, z, 0.0f};
    return v;
}

bool vect_equal(vect3 *a, vect3 *b)
{

    if (epsilon_equal(a->x, b->x) &&
        epsilon_equal(a->y, b->y) &&
        epsilon_equal(a->z, b->z) &&
        epsilon_equal(a->w, b->w))
    {

        return true;
    }
    else
    {
        return false;
    }
}

vect3 add_tuple(vect3 *a, vect3 *b)
{

    vect3 res = {
        .x = a->x + b->x,
        .y = a->y + b->y,
        .z = a->z + b->z,
        .w = a->w + b->w};
    return res;
}

vect3 sub_two_tuples(vect3 *a, vect3 *b)
{

    vect3 res = {
        .x = a->x - b->x,
        .y = a->y - b->y,
        .z = a->z - b->z,
        .w = a->w - b->w};
    return res;
}

vect3 negate(vect3 *a)
{
    vect3 v = {
        .x = -1.0f * a->x,
        .y = -1.0f * a->y,
        .z = -1.0f * a->z,
        .w = -1.0f * a->w};
    return v;
}

vect3 scalar_mult(float scalar, vect3 *b)
{
    vect3 v = {
        .x = b->x * scalar,
        .y = b->y * scalar,
        .z = b->z * scalar,
        .w = b->w * scalar};
    return v;
}

vect3 scalar_div(float scalar, vect3 *b)
{
    vect3 v = {
        .x = b->x / scalar,
        .y = b->y / scalar,
        .z = b->z / scalar,
        .w = b->w / scalar};
    return v;
}

float mag(vect3 *a)
{
    return sqrt(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
}

vect3 norm(vect3 *a)
{
    float inverse_sqrt = inv_sqrt(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
    vect3 v = {
        .x = a->x * inverse_sqrt,
        .y = a->y * inverse_sqrt,
        .z = a->z * inverse_sqrt,
        .w = a->w * inverse_sqrt};
    return v;
}

float dot_p(vect3 *a, vect3 *b)
{
    return (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
}

vect3 cross_p(vect3 *a, vect3 *b){
    vect3 v = vector(
                    (a->y * b->z) - (a->z * b->y),
                    (a->z * b->x) - (a->x * b->z),   
                    (a->x * b->y) - (a->y * b->x));
    return v;
}

bool is_vector(vect3 *v)
{
    return epsilon_equal(0.0f, v->w);
}

bool is_point(vect3 *p)
{
    return epsilon_equal(1.0f, p->w);
}