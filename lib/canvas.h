#ifndef _CANVAS_H_
#define _CANVAS_H_
#include "tuples.h"

typedef struct{
    int width;
    int height;
    color_t* pixel;
}canvas_t;

canvas_t canvas_create(int width, int height);

#endif // _CANVAS_H_