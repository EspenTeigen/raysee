#ifndef MATRICES_H_
#define MATRICES_H_
#include "tuples.h"

typedef double matrix2[2][2];
typedef double matrix3[3][3];
typedef double matrix4[4][4];

bool matrix2_equal(matrix2 mat1, matrix2 mat2);
bool matrix3_equal(matrix3 mat1, matrix3 mat2);
bool matrix4_equal(matrix4 mat1, matrix4 mat2);

void matrix4_mult(matrix4 mat1, matrix4 mat2, matrix4 res);

void matrix4_vect3_mult(matrix4 mat, vect3 vect, vect3 res);

void matrix4_get_identity(matrix4 res);

double matrix4_det(matrix4 a);

void matrix4_transpose(matrix4 a, matrix4 res);

#endif // MATRICES_H_