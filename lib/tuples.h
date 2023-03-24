#ifndef _TUPLES_H_
#define _TUPLES_H_


typedef struct{
    float x;
    float y;
    float z;
    float w;
}vect3;


vect3 tuple(float x, float y, float z, float w);

vect3 point(float x, float y, float z);

vect3 vector(float x, float y, float z);

#endif // _TUPLES_H_