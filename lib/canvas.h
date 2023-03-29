#ifndef CANVAS_H_
#define CANVAS_H_
#include "tuples.h"
#include <stddef.h>
#include <tuples.h>


typedef struct _canvas_t{
    long width;
    long height;
    color_t pixels[];
}canvas_t;

canvas_t* canvas_create(const long width, const long height);
void canvas_delete(canvas_t **canvas);
void canvas_write_pixel(canvas_t *canvas, long x, long y, color_t *color);
void canvas_to_ppm(canvas_t *canvas, const char* canvas_name);
#endif // _CANVAS_H_