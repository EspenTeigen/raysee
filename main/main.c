#include <stdio.h>
#include "tuples.c"
#include "canvas.h"

void projectile_path(void);
void test_canvas(void);

int main(){
    //projectile_path();
    test_canvas();
return 0;
}

void test_canvas(void){
    canvas_t *canvas = canvas_create(5, 5);
    color_t r = color_create(0.9f, 0.5f, 1.0f);
    color_t g = color_create(0.0f, 1.0f, 0.0f);
    color_t b = color_create(0.0f, 0.0f, 1.0f);

   // canvas_write_pixel(canvas, 0, 0, &color);
    canvas_write_pixel(canvas, 0, 1, &r);

    for(int i = 0; i < 5*5; i++){
        printf("i %i\n", i);
        printf("r %f\n", canvas->pixels[i].r);
        printf("g %f\n", canvas->pixels[i].g);
        printf("b %f\n", canvas->pixels[i].b);
    }
    

}

void projectile_path(void){

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
    projectile.velocity = vector(10.0f, 10.0f, 0.0f);

    // Set up environmental factors
    environment.gravity = vector(0.0f, -0.1f, 0.0f);
    environment.wind = vector(-0.1f, 0.0f, 0.0f);

    int tick = 0;

    while(projectile.position.y >= 0){
        tick += 1;
        projectile.position = add_tuple(&projectile.position, &projectile.velocity);
        projectile.velocity = add_tuple(&projectile.velocity, &environment.gravity);
        projectile.velocity = add_tuple(&projectile.velocity, &environment.wind);

        printf("x = %f, y = %f, z=%f, ticks = %i\n", 
            projectile.position.x,  
            projectile.position.y, 
            projectile.position.z, 
            tick);
    }



}