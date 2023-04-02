#include <stdio.h>
#include "tuples.c"
#include "canvas.h"
#include <time.h>

void projectile_path(void);
void test_canvas(void);

int main(){
    printf("start\n");
    projectile_path();
  //  test_canvas();
return 0;
}

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
    canvas_to_ppm(canvas, "../../helvete.ppm");
    endTime = (float)clock()/CLOCKS_PER_SEC;
    printf("runtime canvas write: %f\n", endTime - startTime);
    
    
}

void projectile_path(void){
    
    canvas_t *canvas = canvas_create(2048, 1152);
    color_t yellow;
    color_create(1.0, 1.0, 0.0, &yellow);

    struct _projectile{
        point3 position;
        vect3 velocity;
    }projectile;

    struct _environment{
        vect3 gravity;
        vect3 wind;
    }environment;

    // Set up initial conditions
    point(0.0, 1.0, 0.0, &projectile.position);
    vect3 v;
    vector(1.0, 1.8, 0.0, &v);
    vect3 w;
    norm(&v, &w);
    scalar_mult(11.25, &w, &projectile.velocity) ;

    // Set up environmental factors
    vector(0.0, -0.1, 0.0, &environment.gravity);
    vector(-0.01, 0.0, 0.0, &environment.wind);

    int tick = 0;

    while(projectile.position.y >= 0){
        tick += 1;
        add_tuple(&projectile.position, &projectile.velocity, &projectile.position);
        add_tuple(&projectile.velocity, &environment.gravity, &projectile.velocity);
        add_tuple(&projectile.velocity, &environment.wind, &projectile.velocity);

        long y_pos = canvas->height - projectile.position.y;

        canvas_write_pixel(canvas, projectile.position.x, y_pos, &yellow);
     
    }
    canvas_to_ppm(canvas, "../../faen.ppm");
    canvas_delete(&canvas);
}