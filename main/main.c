#include <stdio.h>
#include "tuples.c"
#include "canvas.h"
#include <time.h>

void projectile_path(void);
void test_canvas(void);

int main(){
    projectile_path();
    //test_canvas();
return 0;
}

void test_canvas(void){

    float startTime = (float)clock()/CLOCKS_PER_SEC;

    canvas_t *canvas = canvas_create(1000, 1000);
    color_t r = color_create(0.9f, 0.5f, 1.0f);
    color_t g = color_create(0.0f, 1.0f, 0.0f);
    color_t b = color_create(1.0f, 1.0f, 1.0f);

    canvas_write_pixel(canvas, 0, 0, &r);
    canvas_write_pixel(canvas, 0, 1, &r);
    canvas_write_pixel(canvas, 1, 1, &b);
    

    float endTime = (float)clock()/CLOCKS_PER_SEC;
    printf("%f", endTime - startTime);
    for(int i = 0; i < 1000*1000; i++){
        canvas_write_pixel(canvas, i, i, &r);
    }
    long x = 0;
    for(int i = 1000; i > 0; i--){
        x++;
        canvas_write_pixel(canvas, x, i, &r);
    }
    canvas_to_ppm(canvas, "../../test.ppm");
    
}

void projectile_path(void){
    
    canvas_t *canvas = canvas_create(900, 550);
    color_t yellow = color_create(1.0f, 1.0f, 0.0f);

    struct _projectile{
        point3 position;
        vect3 velocity;
    }projectile;

    struct _environment{
        vect3 gravity;
        vect3 wind;
    }environment;

    // Set up initial conditions
    projectile.position = point(0.0f, 1.0f, 0.0f);
    vect3 v = vector(1.0f, 1.8f, 0.0f);
    v = norm(&v);
    projectile.velocity = scalar_mult(11.25f, &v) ;

    // Set up environmental factors
    environment.gravity = vector(0.0f, -0.1f, 0.0f);
    environment.wind = vector(-0.01f, 0.0f, 0.0f);

    int tick = 0;

    while(projectile.position.y >= 0){
        tick += 1;
        projectile.position = add_tuple(&projectile.position, &projectile.velocity);
        projectile.velocity = add_tuple(&projectile.velocity, &environment.gravity);
        projectile.velocity = add_tuple(&projectile.velocity, &environment.wind);

        long y_pos = canvas->height - projectile.position.y;

        canvas_write_pixel(canvas, projectile.position.x, y_pos, &yellow);
        printf("x = %f, y = %f, z=%f, ticks = %i\n", 
            projectile.position.x,  
            projectile.position.y, 
            projectile.position.z, 
            tick);
    }
    canvas_to_ppm(canvas, "../../test.ppm");
    canvas_delete(&canvas);


}