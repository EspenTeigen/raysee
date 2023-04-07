#include "projectile_path.h"
#include <stdio.h>
#include <time.h>
#include "canvas.h"
#include "tuples.h"


void projectile_path(void){
    
    canvas_t *canvas = canvas_create(2048, 1152);
    color_t yellow;
    color_create(1.0, 1.0, 0.0, &yellow);

    struct _projectile{
        point3 position;
        vect4 velocity;
    }projectile;

    struct _environment{
        vect4 gravity;
        vect4 wind;
    }environment;

    // Set up initial conditions
    point(0.0, 1.0, 0.0, projectile.position);
    vect4 v;
    vector(1.0, 1.8, 0.0, v);
    vect4 w;
    norm(v, w);
    scalar_mult(11.25, w, projectile.velocity) ;

    // Set up environmental factors
    vector(0.0, -0.1, 0.0, environment.gravity);
    vector(-0.01, 0.0, 0.0, environment.wind);

    int tick = 0;

    while(projectile.position[Y] >= 0){
        tick += 1;
        add_tuple(projectile.position, projectile.velocity, projectile.position);
        add_tuple(projectile.velocity, environment.gravity, projectile.velocity);
        add_tuple(projectile.velocity, environment.wind, projectile.velocity);

        long y_pos = canvas->height - projectile.position[Y];

        canvas_write_pixel(canvas, projectile.position[X], y_pos, &yellow);
     
    }
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    canvas_to_ppm(canvas, "../../main/projectile_path/faen.ppm");
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    printf("runtime canvas create: %f\n", endTime - startTime);
    
    canvas_delete(&canvas);
}