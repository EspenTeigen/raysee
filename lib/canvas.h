#ifndef CANVAS_H_
#define CANVAS_H_
#include "tuples.h"
#include <stddef.h>
#include <tuples.h>

/// @brief used to store the canvas
typedef struct _canvas_t{
    /// @brief pixel width
    long width;
    /// @brief pixel height
    long height;
    /// @brief the pixels
    color_t pixels[];
}canvas_t;

/// @brief Create a canvas
/// @param width pixel width
/// @param height pixel height
/// @return a pointer to the canvas
canvas_t* canvas_create(const long width, const long height);

/// @brief free the malloced canvas
/// @param canvas the canvas to free
void canvas_delete(canvas_t **canvas);

/// @brief Write a pixel to the canvas
/// @param canvas pointer to the canvas created by canvas_create
/// @param x x-pixel to set
/// @param y y pixel to set
/// @param color the color to set the pixel to
void canvas_write_pixel(canvas_t *canvas, long x, long y, color_t *color);

/// @brief Create image in ppm format
/// @param canvas pointer the canvas created by canvas_create
/// @param canvas_name name of canvas
void canvas_to_ppm(canvas_t *canvas, const char* canvas_name);
#endif // _CANVAS_H_