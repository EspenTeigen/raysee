#include "canvas.h"
#include "stdlib.h"
canvas_t canvas_create(int width, int height){
    canvas_t canvas;
    canvas.width = width;
    canvas.height = height;
    canvas.pixel = malloc(sizeof(color_t *) * width * height);
}