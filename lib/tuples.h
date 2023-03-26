#ifndef _TUPLES_H_
#define _TUPLES_H_
#include <stdbool.h>
#define EPSILON 0.0001
typedef struct{
    float x;
    float y;
    float z;
    float w;
}vect3;


vect3 tuple(float x, float y, float z, float w);
vect3 point(float x, float y, float z);
vect3 vector(float x, float y, float z);
bool vect_equal(vect3 *a, vect3 *b);
vect3 add_tuple(vect3 *a, vect3 *b);
vect3 sub_two_tuples(vect3 *a, vect3 *b);
vect3 negate(vect3 *a);
vect3 scalar_mult(float scalar, vect3 *a);
vect3 scalar_div(float scalar, vect3 *a);
float mag(vect3 *a);
vect3 norm(vect3 * a);
vect3 cross_p(vect3 *a, vect3 *b);
float dot_p(vect3 *a, vect3 *b);
bool is_vector(vect3 *v);
bool is_point(vect3 *p);

#endif // _TUPLES_H_