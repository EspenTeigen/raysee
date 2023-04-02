#include "matrices.h"
#include <stdbool.h>
#include <stdio.h>

bool matrix2_equal(matrix2 mat1, matrix2 mat2){
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(!epsilon_equal(mat1[i][j], mat2[i][j])){
                return false;
            }
        }
    }
    
    return true;
}


bool matrix3_equal(matrix3 mat1, matrix3 mat2){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(!epsilon_equal(mat1[i][j], mat2[i][j])){
                return false;
            }
        }
    }
    
    return true;
}

bool matrix4_equal(matrix4 mat1, matrix4 mat2){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(!epsilon_equal(mat1[i][j], mat2[i][j])){
                return false;
            }
        }
    }
    
    return true;
}

void matrix4_mult(matrix4 mat1, matrix4 mat2, matrix4 res){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res[i][j] = 0.0;
            for(int k = 0; k < 4; k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }    
        }
    }
}

void matrix4_vect3_mult(matrix4 mat, vect3 vect, vect3 res){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res[j] += mat[j][i] * vect[i];
        }
    }
}

void matrix4_get_identity(matrix4 res){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                res[i][j] = 1.0;
            }
        }
    }
}

void matrix4_transpose(matrix4 a, matrix4 res){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res[j][i] = a[i][j];
        }
    }
}

double matrix4_det(matrix4 a){
    return a[0][3] * a[1][2] * a[2][1] * a[3][0] - a[0][2] * a[1][3] * a[2][1] * a[3][0] -
           a[0][3] * a[1][1] * a[2][2] * a[3][0] + a[0][1] * a[1][3] * a[2][2] * a[3][0] +
           a[0][2] * a[1][1] * a[2][3] * a[3][0] - a[0][1] * a[1][2] * a[2][3] * a[3][0] -
           a[0][3] * a[1][2] * a[2][0] * a[3][1] + a[0][2] * a[1][3] * a[2][0] * a[3][1] +
           a[0][3] * a[1][0] * a[2][2] * a[3][1] - a[0][0] * a[1][3] * a[2][2] * a[3][1] -
           a[0][2] * a[1][0] * a[2][3] * a[3][1] + a[0][0] * a[1][2] * a[2][3] * a[3][1] +
           a[0][3] * a[1][1] * a[2][0] * a[3][2] - a[0][1] * a[1][3] * a[2][0] * a[3][2] -
           a[0][3] * a[1][0] * a[2][1] * a[3][2] + a[0][0] * a[1][3] * a[2][1] * a[3][2] +
           a[0][1] * a[1][0] * a[2][3] * a[3][2] - a[0][0] * a[1][1] * a[2][3] * a[3][2] -
           a[0][2] * a[1][1] * a[2][0] * a[3][3] + a[0][1] * a[1][2] * a[2][0] * a[3][3] +
           a[0][2] * a[1][0] * a[2][1] * a[3][3] - a[0][0] * a[1][2] * a[2][1] * a[3][3] -
           a[0][1] * a[1][0] * a[2][2] * a[3][3] + a[0][0] * a[1][1] * a[2][2] * a[3][3];
}