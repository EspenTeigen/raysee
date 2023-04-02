/*
    My own implementation of the raytracer challenge book. 

    All tuple/point/vector calculation is here

    There is no null-pointer test because of speed
*/

#ifndef TUPLES_H_
#define TUPLES_H_
#include <stdbool.h>

/// Max error between floats
#define EPSILON 0.0001

/// @brief Vector with w
//typedef struct{
    /// @brief x-coordinate
//    double x;
    /// @brief y-coordinate
//    double y;
    /// @brief z-coordinte
//    double z;
    /// @brief w-coordinate
//    double w;
//}vect3;

typedef enum{
    X = 0,
    Y,
    Z,
    W
}axis_t;

typedef double vect3[4];

// Used to separate between vector and points
typedef vect3 point3;

double inv_sqrt(double a);
bool epsilon_equal(double a, double b);

/// @brief Create a tuple
/// @param x x-coordinate
/// @param y y coordinate
/// @param z z-coordinate
/// @param w w-coordinate 0 if vector and 1 if point
/// @param res result
void tuple(double x, double y, double z, double w, vect3 res);


/// @brief Create a point
/// @param x x-coordinate
/// @param y y coordinate
/// @param z z-coordinate
/// @param res result
void point(double x, double y, double z, vect3 res);

/// @brief Create a vector
/// @param x x-coordinate
/// @param y y coordinate
/// @param z z-coordinate
/// @param res result
void vector(double x, double y, double z, vect3 res);

/// @brief Check if two vectors are equal
/// @param a vector 1
/// @param b vector 2
/// @return true if equal, false if not
bool tuple_equal(vect3 a, vect3 b);

/// @brief Add two tuples, accept both vectors and points.
/// @param a vector 1
/// @param b vector 2
/// @param res result
void add_tuple(vect3 a, vect3 b, vect3 res);

/// @brief Subtract two tuples, accept both vectors and points
/// @param a vector 1
/// @param b vector 2
/// @param res result
void sub_two_tuples(vect3 a, vect3 b, vect3 res);

/// @brief Negate a vector
/// @param a vector to negate
/// @param res result
void negate(vect3 a, vect3 res);


/// @brief Multiply a scalar with a vector
/// @param scalar A scalar
/// @param a a vector
/// @param res result
void scalar_mult(double scalar, vect3 a, vect3 res);


/// @brief Divide a scalar with a vector
/// @param scalar A scalar
/// @param a a vector
/// @param res result
void scalar_div(double scalar, vect3 a, vect3 res);

/// @brief Find the magnitude of a vector
/// @param a the vector to normalize
/// @return float with the magnitude
double mag(vect3 a);

/// @brief Normalize a vector
/// @param a the vector to normalize 
/// @param res result
void norm(vect3 a, vect3 res);


/// @brief Calculate the cross product og two vectors, only works for vectors
/// @param a vector 1
/// @param b vector 2
/// @param res result
void cross_p(vect3 a, vect3 b, vect3 res);

/// @brief Take the dot product
/// @param a vector 1
/// @param b vector 2
/// @return float with the dot product
double dot_p(vect3 a, vect3 b);

/// @brief Check if a tuple is a vector
/// @param v the tuple to check
/// @return bool true if it is a vector
bool is_vector(vect3 v);

/// @brief Check if tuple is a point
/// @param p the point to check
/// @return bool true if it is a vector
bool is_point(vect3 p);

//----------- colors ---------------

/// @brief vector of color
typedef struct{
    double r;
    double g;
    double b;
}color_t;


/// @brief create a color
/// @param r red component
/// @param g green component
/// @param b blue component
/// @param res result
void color_create(double r, double g, double b, color_t *res);


/// @brief add two colors together
/// @param c1 color 1
/// @param c2 color 2
/// @param res result
void color_add(color_t *c1, color_t *c2, color_t *res);


/// @brief subtract a color from another
/// @param c1 color to be subtracted from
/// @param c2 color to subtract
/// @param res result
void color_sub(color_t *c1, color_t *c2, color_t *res);

/// @brief multiply a scalar with a color
/// @param scalar how much to scale with
/// @param c color to scale
/// @param res result
void color_scalar_mult(double scalar, color_t *c, color_t *res);

/// @brief multiply two colors
/// @param c1 color 1
/// @param c2 color 2
/// @param res result
void color_mult(color_t *c1, color_t *c2, color_t *res);

#endif // _TUPLES_H_