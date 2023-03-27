#include "canvas.h"
#include "stdlib.h"
canvas_t canvas_create(int width, int height){
        canvas_t* canvas = malloc(sizeof(*canvas) + sizeof(color_t[width*height]));
        canvas->height = height;
        canvas->width = width;
        for(int i = 0; i < (width*height); i++){
            canvas->pixel->r = 0.0f;
            canvas->pixel->g = 1.0f;
            canvas->pixel->b = 0.0f;
        }
    return *canvas;
}