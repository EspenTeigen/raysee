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

double matrix2_det(matrix2 a){
    return a[0][0] * a[1][1] - a[0][1]*a[1][0];
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



void matrix3_submatrix(matrix3 a, const int row, const int col, matrix2 res){

    int k = 0;
    int l = 0;

    for(int i = 0; i < 3; i++){
        if(i != row){ 
            for(int j = 0; j < 3; j++){
                if(j != col){
                    res[k][l] = a[i][j];
                    l++;
                }
            }
            l = 0;
            k++;
        }
    }
}

double matrix3_minor(matrix3 a, const int row, const int col){
    matrix2 b = {0};
    matrix3_submatrix(a, row, col, b);
    return matrix2_det(b);
}

double matrix3_cofactor(matrix3 a, const int row, const int col){

    double minor = matrix3_minor(a, row, col);

    if((row+col % 2) != 0){
        minor = -minor;
    }

    return minor;
}

double matrix3_det(matrix3 a){
    double det = 0;

    for(int i = 0; i < 3; i++){
        det += a[0][i] * matrix3_cofactor(a, 0, i);
    }
    return det;
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

void matrix4_vect3_mult(matrix4 mat, vect4 vect, vect4 res){
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
            else{
                res[i][j] = 0.0;
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


void matrix4_submatrix(matrix4 a, const int row, const int col, matrix3 res){
    int k = 0;
    int l = 0;

    for(int i = 0; i < 4; i++){
        if(i != row){ 
            for(int j = 0; j < 4; j++){
                if(j != col){
                    res[k][l] = a[i][j];
                    l++;
                }
            }
            l = 0;
            k++;
        }   
    }
}

double matrix4_minor(matrix4 a, const int row, const int col){
    matrix3 b = {0};
    matrix4_submatrix(a, row, col, b);
    return matrix3_det(b);
}

double matrix4_cofactor(matrix4 a, const int row, const int col){

    double minor = matrix4_minor(a, row, col);

    if(((row+col) % 2) != 0){
        minor *= (-1);
    }
 
    return minor;
}

double matrix4_det(matrix4 a){
    double det = 0;

    for(int i = 0; i < 4; i++){
        det += a[0][i] * matrix4_cofactor(a, 0, i);
    }
    return det;
}


bool matrix4_is_invertible(matrix4 a){
    if(matrix4_det(a) != 0.0){
        return true;
    }
    else{
        return false;
    }
}

bool matrix4_inverse(matrix4 a, matrix4 res){

    double cof = 0;
    double det = matrix4_det(a);
    bool invertible = false;

    if(!epsilon_equal(det, 0.0)){

        invertible = true;
        double det_inv = 1.0/det;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cof = matrix4_cofactor(a, i, j);
                res[j][i] = cof * det_inv; 
            }
        }
    }

    return invertible;
}