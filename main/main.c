#include <stdio.h>
#include "tuples.c"

void projectile_path(void);

int main(){
    projectile_path();
return 0;
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