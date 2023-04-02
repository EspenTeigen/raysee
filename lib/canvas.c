#include "canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COLOR_VALUE 255L
#define MIN_COLOR_VALUE 0L
const long MAX_LINE_LENGTH = 70;

double map_and_clamp_color(double color){

    color = color * MAX_COLOR_VALUE;

    if(color > MAX_COLOR_VALUE){
        color = MAX_COLOR_VALUE;
    }
    else if(color < MIN_COLOR_VALUE){
        color = MIN_COLOR_VALUE;
    }
    return round(color);
}


void print_pixels(canvas_t *canvas, FILE *fp){
    int num_char = 0;

    fprintf(fp, "P3\n");
    fprintf(fp, "%ld %ld\n%ld\n", canvas->width, canvas->height, MAX_COLOR_VALUE);
    for(long y = 0; y < canvas->height; y++){
        for(long x = 0; x < canvas->width; x++){
            long pos = x + canvas->width * y;
            num_char += fprintf(fp, "%i %i %i ", (int)canvas->pixels[pos].r, (int)canvas->pixels[pos].g, (int)canvas->pixels[pos].b);
            if(num_char >= (MAX_LINE_LENGTH - 6)){
               fprintf(fp, "\n");
               num_char = 0;
            }
        }
    }
}   

canvas_t* canvas_create(long width, long height){

    canvas_t *canvas = (canvas_t*)malloc(sizeof(*canvas) + 3*width*height*sizeof(double));
    if(canvas){
        canvas->height = height;
        canvas->width = width;
        for(int i = 0; i < (width*height); i++){
            canvas->pixels[0].r = 0.0;
            canvas->pixels[0].g = 0.0;
            canvas->pixels[0].b = 0.0;
        }
        return canvas;
    }
    else{
        printf("malloc failed");
        return 0;
    }
}

void canvas_delete(canvas_t **canvas){
    free(*canvas);
    *canvas = NULL;
}

void canvas_write_pixel(canvas_t *canvas, long x, long y, color_t *color){
    
    long pos = x + canvas->width * y;

    if(pos <= (canvas->width*canvas->height)){
        canvas->pixels[pos].r = color->r;
        canvas->pixels[pos].g = color->g;
        canvas->pixels[pos].b = color->b;
    }
    
}

void canvas_to_ppm(canvas_t *canvas, const char* canvas_name){
    
    for(int i = 0; i < (canvas->width * canvas->height); i++){
        canvas->pixels[i].r = map_and_clamp_color(canvas->pixels[i].r);
        canvas->pixels[i].g = map_and_clamp_color(canvas->pixels[i].g);
        canvas->pixels[i].b = map_and_clamp_color(canvas->pixels[i].b);
    }

    FILE *fp;
    fp = fopen(canvas_name, "w");
    if(fp){
        print_pixels(canvas, fp);
        fclose(fp);
    }
}