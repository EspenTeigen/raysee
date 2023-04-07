#include "transformations.h"
#include "stdbool.h"
#include <math.h>
#include <string.h>



void transformation_get_translate(double x, double y, double z, matrix4 res){

    matrix4_get_identity(res);

    res[0][3] = x;
    res[1][3] = y;
    res[2][3] = z;

}

void transformation_get_scaling(double x, double y, double z, matrix4 res){
    
    vect4 v;
    v[X] = x;
    v[Y] = y;
    v[Z] = z;
    v[W] = 1.0;

    int k = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                res[i][j] = v[k];
                k++;
            }
            else{
                res[i][j] = 0.0;
            }
        }
    }
}

void transformation_get_rotx(double angle, matrix4 res){
    matrix4 temp = {
        {1.0,   0.0,            0.0,            0.0},
        {0.0,   cos(angle),    -sin(angle),     0.0},
        {0.0,   sin(angle),     cos(angle),     0.0},
        {0.0,   0.0,            0.0,            1.0}
    };

    memcpy(res, temp, sizeof(matrix4));
}

void transformation_get_roty(double angle, matrix4 res){
    matrix4 temp = {
        {cos(angle),    0.0,    sin(angle),     0.0},
        {0.0,           1.0,    0.0,            0.0},
        {-sin(angle),   0.0,    cos(angle),     0.0},
        {0.0,           0.0,    0.0,            1.0}
    };
    memcpy(res, temp, sizeof(matrix4));
}

void transformation_get_rotz(double angle, matrix4 res){
    matrix4 temp = {
        {cos(angle),   -sin(angle),     0.0,    0.0},
        {sin(angle),    cos(angle),     0.0,    0.0},
        {0.0,           0.0,            0.0,    0.0},
        {0.0,           0.0,            0.0,    1.0}
    };
    
    memcpy(res, temp, sizeof(matrix4));
}

void transformation_get_shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y, matrix4 res){
    matrix4 temp = {
        {1,    x_y,    x_z,    0.0},
        {y_x,  1.0,    y_z,    0.0},
        {z_x,  z_y,    1.0,    0.0},
        {0.0,  0.0,    0.0,    1.0}
    };

    memcpy(res, temp, sizeof(matrix4));
}