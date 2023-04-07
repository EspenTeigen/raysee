#ifndef TRANSFORMATIONS_H_
#define TRANSFORMATIONS_H_
#include "tuples.h"
#include "matrices.h"


void transformation_get_translate(double x, double y, double z, matrix4 res);

void transformation_get_scaling(double x, double y, double z, matrix4 res);

void transformation_get_rotx(double angle, matrix4 res);

void transformation_get_roty(double angle, matrix4 res);

void transformation_get_rotz(double angle, matrix4 res);

/// @brief get shearing matrix
/// @param x_y x in proportion to y
/// @param x_z x in proportion to z
/// @param y_x y in proportion to x
/// @param y_z y in proportion to z
/// @param z_x z in proportion to x
/// @param z_y z in proportion to y
/// @param res matrix4 resulting matrix
void transformation_get_shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y, matrix4 res);

#endif