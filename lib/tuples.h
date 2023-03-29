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
typedef struct{
    /// @brief x-coordinate
    float x;
    /// @brief y-coordinate
    float y;
    /// @brief z-coordinte
    float z;
    /// @brief w-coordinate
    float w;
}vect3;


// Used to separate between vector and points
typedef vect3 point3;

/// @brief Create a tuple
/// @param x x-coordinate
/// @param y y coordinate
/// @param z z-coordinate
/// @param w w-coordinate 0 if vector and 1 if point
/// @return vect3 struct with x, y, z, w coordinates
vect3 tuple(float x, float y, float z, float w);

/// @brief Create a point
/// @param x x-coordinate
/// @param y y coordinate
/// @param z z-coordinate
/// @return a vect3 with w=1.0f
vect3 point(float x, float y, float z);

/// @brief Create a vector
/// @param x x-coordinate
/// @param y y coordinate
/// @param z z-coordinate
/// @return vect3 vector with w=0.0f
vect3 vector(float x, float y, float z);

/// @brief Check if two vectors are equal
/// @param a vector 1
/// @param b vector 2
/// @return true if equal, false if not
bool tuple_equal(vect3 *a, vect3 *b);

/// @brief Add two tuples, accept both vectors and points.
/// @param a vector 1
/// @param b vector 2
/// @return vect3 containg the result
vect3 add_tuple(vect3 *a, vect3 *b);

/// @brief Subtract two tuples, accept both vectors and points
/// @param a vector 1
/// @param b vector 2
/// @return vect3 containg the result
vect3 sub_two_tuples(vect3 *a, vect3 *b);

/// @brief Negate a vector
/// @param a vector to negate
/// @return vect3 containing the result
vect3 negate(vect3 *a);

/// @brief Multiply a scalar with a vector
/// @param scalar A scalar
/// @param a a vector
/// @return vect3 containing the result
vect3 scalar_mult(float scalar, vect3 *a);

/// @brief Divide a scalar with a vector
/// @param scalar A scalar
/// @param a a vector
/// @return vect3 containing the result
vect3 scalar_div(float scalar, vect3 *a);

/// @brief Find the magnitude of a vector
/// @param a the vector to normalize
/// @return float with the magnitude
float mag(vect3 *a);

/// @brief Normalize a vector
/// @param a the vector to normalize 
/// @return vect3 containing the result
vect3 norm(vect3 * a);

/// @brief Calculate the cross product og two vectors, only works for vectors
/// @param a vector 1
/// @param b vector 2
/// @return vect3 containing the cross product
vect3 cross_p(vect3 *a, vect3 *b);

/// @brief Take the dot product
/// @param a vector 1
/// @param b vector 2
/// @return float with the dot product
float dot_p(vect3 *a, vect3 *b);

/// @brief Check if a tuple is a vector
/// @param v the tuple to check
/// @return bool true if it is a vector
bool is_vector(vect3 *v);

/// @brief Check if tuple is a point
/// @param p the point to check
/// @return bool true if it is a vector
bool is_point(vect3 *p);

//----------- colors ---------------

/// @brief vector of color
typedef struct{
    float r;
    float g;
    float b;
}color_t;

/// @brief create a color
/// @param r red component
/// @param g green component
/// @param b blue component
/// @return color struct containing colors
color_t color_create(float r, float g, float b);

/// @brief add two colors together
/// @param c1 color 1
/// @param c2 color 2
/// @return color containing result
color_t color_add(color_t *c1, color_t *c2);

/// @brief subtract a color from another
/// @param c1 color to be subtracted from
/// @param c2 color to subtract
/// @return color containing result
color_t color_sub(color_t *c1, color_t *c2);

/// @brief multiply a scalar with a color
/// @param scalar how much to scale with
/// @param c color to scale
/// @return color containg result
color_t color_scalar_mult(float scalar, color_t *c);

/// @brief multiply two colors
/// @param c1 color 1
/// @param c2 color 2
/// @return color containing the result
color_t color_mult(color_t *c1, color_t *c2);

#endif // _TUPLES_H_