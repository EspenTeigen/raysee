#include "canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_COLOR_VALUE 255L
#define MIN_COLOR_VALUE 0l


static inline float map_and_clamp_color(float color){

    color = color * MAX_COLOR_VALUE;

    if(color > MAX_COLOR_VALUE){
        color = MAX_COLOR_VALUE;
    }
    else if(color < MIN_COLOR_VALUE){
        color = MAX_COLOR_VALUE;
    }
    return (float)round((double)color);
}


static inline void make_ppm_header(FILE *fp, long width, long height){
    fprintf(fp, "P3\n");
    fprintf(fp, "%ld %ld\n%ld\n", width, height, MAX_COLOR_VALUE);
}

static inline void print_pixels(canvas_t *canvas, long width, long height, FILE *fp){
    for(long y = 0; y < height; y++){
        for(long x = 0; x < width; x++){
            long pos = x + canvas->width * y;
            fprintf(fp, "%i %i %i ", (int)canvas->pixels[pos].r, (int)canvas->pixels[pos].g, (int)canvas->pixels[pos].b);
    
        }
        fprintf(fp, "\n");
    }
}   

canvas_t* canvas_create(const long width, const long height){
    
    canvas_t *canvas = malloc(sizeof(*canvas) * sizeof(color_t[width*height]));
    canvas->height = height;
    canvas->width = width;

    for(int i = 0; i < (width*height); i++){
        canvas->pixels[0].r = 0.0f;
        canvas->pixels[0].g = 0.0f;
        canvas->pixels[0].b = 0.0f;
    }
    return canvas;
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
        make_ppm_header(fp, canvas->width, canvas->height);
        print_pixels(canvas, canvas->width, canvas->height, fp);
        fclose(fp);
    }
}