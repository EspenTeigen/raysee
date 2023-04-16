#include "analog_clock.h"

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <transformations.h>
#include <tuples.h>
#include <matrices.h>
#include <canvas.h>
#include <tuples.h>

#define RAD_HOUR (M_PI / 6.0)

void analog_clock(void)
{   
    const long width = 2000;
    const long height = 2000;

    const long radius = width*0.4;

    // start time
    float startTime = (float)clock()/CLOCKS_PER_SEC;

    canvas_t *canvas = canvas_create(width, height);

    // create color for points
    color_t white = {0};
    color_create(1, 1, 1, &white);

    vect4 start_point = {0};
    point(0.0, radius, 0.0, start_point);
    
    for(int i = 0; i < 12; i++){
        matrix4 rot_z = {0};
        transformation_get_rotz(RAD_HOUR*(double)i, rot_z);
        matrix4 translate = {0};
        transformation_get_translate(canvas->width/2.0, canvas->width/2, 0.0, translate);
        matrix4 res = {0};
        matrix4_mult(translate, rot_z, res);
        vect4 new_point = {0};
        matrix4_vect3_mult(res, start_point, new_point);
        canvas_write_pixel(canvas, new_point[X], new_point[Y], &white);
    }

    canvas_to_ppm(canvas, "../../main//analog_clock/satan.ppm");
    canvas_delete(&canvas);

    // get end time
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    printf("runtime canvas write: %f\n", endTime - startTime);
}
