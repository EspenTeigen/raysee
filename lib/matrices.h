#ifndef MATRICES_H_
#define MATRICES_H_
#include "tuples.h"

typedef double matrix2[2][2];
typedef double matrix3[3][3];
typedef double matrix4[4][4];

bool matrix2_equal(matrix2 mat1, matrix2 mat2);
double matrix2_det(matrix2 a);

bool matrix3_equal(matrix3 mat1, matrix3 mat2);
void matrix3_submatrix(matrix3 a, const int row, const int col, matrix2 res);
double matrix3_minor(matrix3 a, const int row, const int col);
double matrix3_cofactor(matrix3 a, const int row, const int col);
double matrix3_det(matrix3 a);

bool matrix4_equal(matrix4 mat1, matrix4 mat2);
void matrix4_mult(matrix4 mat1, matrix4 mat2, matrix4 res);
void matrix4_vect3_mult(matrix4 mat, vect3 vect, vect3 res);
void matrix4_get_identity(matrix4 res);
void matrix4_submatrix(matrix4 a, const int row, const int col, matrix3 res);
double matrix4_minor(matrix4 a, const int row, const int col);
double matrix4_cofactor(matrix4 a, const int row, const int col);
double matrix4_det(matrix4 a);
bool matrix4_is_invertible(matrix4 a);
bool matrix4_inverse(matrix4 a, matrix4 res);
void matrix4_transpose(matrix4 a, matrix4 res);

#endif // MATRICES_H_