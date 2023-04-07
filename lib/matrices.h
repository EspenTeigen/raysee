#ifndef MATRICES_H_
#define MATRICES_H_
#include "tuples.h"

/// @brief 2x2 matrix
typedef double matrix2[2][2];

/// @brief 3x3 matrix
typedef double matrix3[3][3];

/// @brief 4x4 matrix
typedef double matrix4[4][4];

/// @brief Check if two 2x2 matrices are equal
/// @param mat1 first matrix
/// @param mat2 second matrix
/// @return true if equal
bool matrix2_equal(matrix2 mat1, matrix2 mat2);

/// @brief finds determinant 
/// @param a the 2x2 matrix
/// @return the determinant
double matrix2_det(matrix2 a);

/// @brief check if two 3x3 matrices are equal
/// @param mat1 first matrix
/// @param mat2 second matrix
/// @return true if equal
bool matrix3_equal(matrix3 mat1, matrix3 mat2);

/// @brief get the submatrix of a 3x3 matrix
/// @param a matrix3: to get submatrix from
/// @param row row to remove
/// @param col column to remove
/// @param res a 2x2 submatrix
void matrix3_submatrix(matrix3 a, const int row, const int col, matrix2 res);

/// @brief finds the minor of a 3x3 matrix
/// @param a matrix3: the 3x3 matrix
/// @param row row to exclude when finding the minor
/// @param col column to exclude when finding the minor
/// @return the minor of a 3x3 matrix
double matrix3_minor(matrix3 a, const int row, const int col);

/// @brief 
/// @param a 
/// @param row 
/// @param col 
/// @return 
double matrix3_cofactor(matrix3 a, const int row, const int col);

/// @brief get determinant
/// @param a matrix3: matrix to get determinant from
/// @return the determinant
double matrix3_det(matrix3 a);

/// @brief Check if two 4x4 matrices are equal
/// @param mat1 matrix4
/// @param mat2 matrix4
/// @return true if equal
bool matrix4_equal(matrix4 mat1, matrix4 mat2);

/// @brief Multiply two 4x4 matrices
/// @param mat1 matrix4
/// @param mat2 matrix4
/// @param res result of operation
void matrix4_mult(matrix4 mat1, matrix4 mat2, matrix4 res);

/// @brief Multiply a 4x4 matrix with a vector
/// @param mat matrix4 matrix to multiply with
/// @param vect vect4 vector to multiply with
/// @param res vect4 containing result
void matrix4_vect3_mult(matrix4 mat, vect4 vect, vect4 res);

/// @brief get a 4x4 identity matrix
/// @param res matrix4: the identity matrix returned
void matrix4_get_identity(matrix4 res);

void matrix4_submatrix(matrix4 a, const int row, const int col, matrix3 res);
double matrix4_minor(matrix4 a, const int row, const int col);
double matrix4_cofactor(matrix4 a, const int row, const int col);
double matrix4_det(matrix4 a);
bool matrix4_is_invertible(matrix4 a);
bool matrix4_inverse(matrix4 a, matrix4 res);
void matrix4_transpose(matrix4 a, matrix4 res);

#endif // MATRICES_H_