#include <unity.h>
#include <stdlib.h>
#include <tuples.h>
#include <canvas.h>
#include <rays.h>
#include <transformations.h>

void setUp(void) {
    
}

void tearDown(void) {
    // clean stuff up here
}

void test_creating_and_queyring_ray(void){
    
    point4 p;
    point(1.0, 2.0, 3.0, p);
    vect4 v;
    vector(4.0, 5.0, 6.0, v);

    ray_t r = ray(p, v);

    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(p, r.origin, 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(v, r.direction, 4);
}

void test_compute_point_from_distance(void){
    
    point4 p;
    vect4 v;

    point(2.0, 3.0, 4.0, p);
    vector(1.0, 0.0, 0.0, v);
    
    ray_t r = ray(p, v);

    point4 new_point = {0};
    rays_position(&r, 0.0, new_point);
    TEST_ASSERT_EQUAL_DOUBLE(2.0, new_point[X]);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, new_point[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, new_point[Z]);
    
    rays_position(&r, 1.0, new_point);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, new_point[X]);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, new_point[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, new_point[Z]);

    rays_position(&r, -1.0, new_point);
    TEST_ASSERT_EQUAL_DOUBLE(1.0, new_point[X]);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, new_point[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, new_point[Z]);

    rays_position(&r, 2.5, new_point);
    TEST_ASSERT_EQUAL_DOUBLE(4.5, new_point[X]);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, new_point[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, new_point[Z]);
}

void test_ray_intersect_sphere_two_points(void){
    point4 p;
    point(0.0, 0.0, -5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);
    sphere_t s = sphere();

    intersections_t *xs = rays_alloc_intersections_t(2);
    matrix4 T;
 
    sphere_intersect(&s, &r, xs);
 
    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE(6.0, xs->xs[1].t);
    free(xs);
}

void test_ray_intersect_sphere_tangent(void){
    point4 p;
    point(0.0, 1.0, -5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);
    sphere_t s = sphere();

    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(5.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE(5.0, xs->xs[1].t);
    free(xs);
}

void test_ray_miss_sphere(void){
    point4 p;
    point(0.0, 2.0, -5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);
    sphere_t s = sphere();

    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(0, xs->count);
    free(xs);
}

void test_ray_inside_sphere(void){
    point4 p;
    point(0.0, 0.0, 0.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);
    sphere_t s = sphere();

    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(-1.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE( 1.0, xs->xs[1].t);
    free(xs);
}

void test_ray_behind_sphere(void){
    point4 p;
    point(0.0, 0.0, 5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);
    sphere_t s = sphere();

    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(-6.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE(-4.0, xs->xs[1].t);
    free(xs);
}

void test_intersection_encapsulate_t_and_object(void){

    sphere_t s = sphere();
    intersect_t i;
    rays_intersection(3.5, &s, &i);

    TEST_ASSERT_EQUAL_DOUBLE(3.5, i.t);
    TEST_ASSERT_EQUAL_INT(s.object, i.object);

}

void test_aggreagating_intersections(void){
    sphere_t s = sphere();

    intersect_t i1;
    intersect_t i2;
    rays_intersection(1.0, &s, &i1);
    rays_intersection(2.0, &s, &i2);
    intersect_t it[2] = {i1, i2};

    intersections_t *xs = rays_alloc_intersections_t(2);
    rays_intersections(it, 2, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(1.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE(2.0, xs->xs[1].t);
    free(xs);
}

void test_intersect_set_the_object_on_the_intersection(void){

    point4 p;
    point(0.0, 0.0, -5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);
    
    sphere_t s = sphere();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%f " , s.transform[i][j]);
        }
        printf("\n");
    }

   // matrix4 T;
   // transformation_get_scaling(1.0, 1.0, 1.0, T);
   // sphere_set_transform(&s, T);
    intersections_t *xs = rays_alloc_intersections_t(2);
    //for(int i = 0; i < 4; i++){
    //    for(int j = 0; j < 4; j++){
    //        printf("%f " , s.transform[i][j]);
    //    }
    //    printf("\n");
    //}
    
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(SPHERE, xs->xs[0].object);
    TEST_ASSERT_EQUAL_DOUBLE(SPHERE, xs->xs[1].object);   
    free(xs);
}

void test_the_hit_when_all_intersections_have_positive_t(void){
    

    sphere_t s = sphere();
    intersect_t i1;
    rays_intersection(1.0, &s, &i1);
    intersect_t i2;
    rays_intersection(2.0, &s, &i2);
    intersect_t intersections[2] = {i1, i2};
    intersections_t *xs = rays_alloc_intersections_t(2);
    rays_intersections(intersections, 2, xs);
    intersect_t i;
    rays_hit(xs, &i);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, i1.t, i.t);
    free(xs);
}

void test_the_hit_when_some_intersections_have_negative_t(void){
    sphere_t s = sphere();
    intersect_t i1;
    rays_intersection(1.0, &s, &i1);
    intersect_t i2;
    rays_intersection(-1.0, &s, &i2);
    intersect_t intersections[2] = {i1, i2};
    intersections_t *xs = rays_alloc_intersections_t(2);
    rays_intersections(intersections, 2, xs);
    intersect_t i;
    rays_hit(xs, &i);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, i1.t, i.t);
    free(xs);
}

void test_the_hit_when_all_intersections_have_negative_t(void){
    
    sphere_t s = sphere();
    intersect_t i1;
    rays_intersection(-1.0, &s, &i1);
    intersect_t i2;
    rays_intersection(-2.0, &s, &i2);
    intersect_t intersections[2] = {i1, i2};
    intersections_t *xs = rays_alloc_intersections_t(2);
    rays_intersections(intersections, 2, xs);
    intersect_t i;
    rays_hit(xs, &i);
 
    TEST_ASSERT_DOUBLE_IS_NAN(i.t);
    free(xs);
}

void test_hit_is_lowest_nonnegative_intersection(void){
    sphere_t s = sphere();
    intersect_t i1;
    rays_intersection(5.0, &s, &i1);
    intersect_t i2;
    rays_intersection(-7.0, &s, &i2);
    intersect_t i3;
    rays_intersection(-3.0, &s, &i3);
    intersect_t i4;
    rays_intersection(2.0, &s, &i4);

    intersect_t intersections[4] = {i1, i2, i3, i4};
    intersections_t *xs = rays_alloc_intersections_t(4);
    rays_intersections(intersections, 4 , xs);

    intersect_t i;
    rays_hit(xs, &i);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, i4.t, i.t);
    free(xs);
}

void test_translate_a_ray(void){
    point4 origin;
    point(1.0, 2.0, 3.0, origin);
    vect4 direction;
    vector(0.0, 1.0, 0.0, direction);

    ray_t r = ray(origin, direction);
    matrix4 transform = {0};
    transformation_get_translate(3.0, 4.0, 5.0, transform);

    ray_t r2 = {0};
    rays_transform(&r, transform, &r2);

    point4 p_expected; 
    point(4.0, 6.0, 8.0, p_expected);
    vect4 v_expected;
    vector(0.0, 1.0, 0.0, v_expected);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(p_expected, r2.origin, 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(v_expected, r2.direction, 4);
}

void test_scale_ray(void){
    point4 origin;
    point(1.0, 2.0, 3.0, origin);
    vect4 direction;
    vector(0.0, 1.0, 0.0, direction);

    ray_t r = ray(origin, direction);
    matrix4 transform = {0};
    transformation_get_scaling(2.0, 3.0, 4.0, transform);

    ray_t r2 = {0};
    rays_transform(&r, transform, &r2);

    point4 p_expected; 
    point(2.0, 6.0, 12.0, p_expected);
    vect4 v_expected;
    vector(0.0, 3.0, 0.0, v_expected);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(p_expected, r2.origin, 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(v_expected, r2.direction, 4);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_creating_and_queyring_ray);
    RUN_TEST(test_compute_point_from_distance);
    RUN_TEST(test_ray_intersect_sphere_two_points);
    RUN_TEST(test_ray_intersect_sphere_tangent);
    RUN_TEST(test_ray_miss_sphere);
    RUN_TEST(test_ray_inside_sphere);
    RUN_TEST(test_intersection_encapsulate_t_and_object);
    RUN_TEST(test_aggreagating_intersections);
    RUN_TEST(test_intersect_set_the_object_on_the_intersection);
    RUN_TEST(test_the_hit_when_all_intersections_have_positive_t);
    RUN_TEST(test_the_hit_when_some_intersections_have_negative_t);
    RUN_TEST(test_the_hit_when_all_intersections_have_negative_t);
    RUN_TEST(test_hit_is_lowest_nonnegative_intersection);
    RUN_TEST(test_translate_a_ray);
    RUN_TEST(test_scale_ray);
    return UNITY_END();
}