#include "create_canvas.h"
#include <stdio.h>
#include <time.h>
#include "canvas.h"
#include "tuples.h"

void test_canvas(void){

    long width = 1000L;
    long height = 1000L;

    color_t color;
    color_create(0.0, 0.5, 1.0, &color);

    float startTime = (float)clock()/CLOCKS_PER_SEC;
    canvas_t *canvas = canvas_create(width, height);

    for(long j = 0; j < height; j++){
        for(long i = 0; i < width; i++){
            canvas_write_pixel(canvas, i, j, &color);
        }
    }

    float endTime = (float)clock()/CLOCKS_PER_SEC;

    printf("runtime canvas create: %f\n", endTime - startTime);

    startTime = (float)clock()/CLOCKS_PER_SEC;
    canvas_to_ppm(canvas, "../../main/create_canvas/helvete.ppm");
    endTime = (float)clock()/CLOCKS_PER_SEC;
    printf("runtime canvas write: %f\n", endTime - startTime);
    canvas_delete(&canvas);
}