#include <unity.h>
#include <stdlib.h>
#include <tuples.h>
#include <canvas.h>
#include <rays.h>

void setUp(void) {
    
}

void tearDown(void) {
    // clean stuff up here
}

void test_creating_and_queyring_ray(void){
    ray_t r;
    point4 p;
    point(1.0, 2.0, 3.0, p);
    vect4 v;
    vector(4.0, 5.0, 6.0, v);

    rays_ray(p, v, &r);

    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(p, r.origin, 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(v, r.direction, 4);
}

void test_compute_point_from_distance(void){
    ray_t r;
    point4 p;
    vect4 v;

    point(2.0, 3.0, 4.0, p);
    vector(1.0, 0.0, 0.0, v);
    
    rays_ray(p, v, &r);

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
    ray_t r;
    rays_ray(p, v, &r);
    sphere_t s;
    rays_sphere(&s);

    intersections_t *xs = rays_alloc_intersections_t(2);

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
    ray_t r;
    rays_ray(p, v, &r);
    sphere_t s;
    rays_sphere(&s);

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
    ray_t r;
    rays_ray(p, v, &r);
    sphere_t s;
    rays_sphere(&s);

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
    ray_t r;
    rays_ray(p, v, &r);
    sphere_t s;
    rays_sphere(&s);

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
    ray_t r;
    rays_ray(p, v, &r);
    sphere_t s;
    rays_sphere(&s);

    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(-6.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE(-4.0, xs->xs[1].t);
    free(xs);
}

void test_intersection_encapsulate_t_and_object(void){

    sphere_t s;
    rays_sphere(&s);
    intersect_t i;
    rays_intersection(3.5, &s, &i);

    TEST_ASSERT_EQUAL_DOUBLE(3.5, i.t);
    TEST_ASSERT_EQUAL_INT(s.object, i.object);

}

void test_aggreagating_intersections(void){
    sphere_t s;
    rays_sphere(&s);

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
    ray_t r;
    rays_ray(p, v, &r);

    sphere_t s;
    rays_sphere(&s);
    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_INT32(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(SPHERE, xs->xs[0].object);
    TEST_ASSERT_EQUAL_DOUBLE(SPHERE, xs->xs[1].object);   
    free(xs);
}

void test_the_hit_when_all_intersections_have_positive_t(void){
    
    sphere_t s;
    rays_sphere(&s);
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

void test_the_hit_when_all_intersections_have_negative_t(void){
    
    sphere_t s;
    rays_sphere(&s);
    intersect_t i1;
    rays_intersection(-1.0, &s, &i1);
    intersect_t i2;
    rays_intersection(2.0, &s, &i2);
    intersect_t intersections[] = {i1, i2};
    intersections_t *xs = rays_alloc_intersections_t(sizeof(intersections)/sizeof(intersections[0]));
    rays_intersections(intersections, sizeof(intersections)/sizeof(intersections[0]), xs);
    intersect_t i;
    rays_hit(xs, &i);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, i2.t,      i.t);
    free(xs);
}

void test_the_hit_when_all_intersections_all_negative_t(void){
    
    sphere_t s;
    rays_sphere(&s);
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
    sphere_t s;
    rays_sphere(&s);
    intersect_t i1;
    rays_intersection(5.0, &s, &i1);
    intersect_t i2;
    rays_intersection(7.0, &s, &i2);
    intersect_t i3;
    rays_intersection(-3.0, &s, &i2);
    intersect_t i4;
    rays_intersection(2.0, &s, &i2);

    intersect_t intersections[] = {i1, i2, i3, i4};
    intersections_t *xs = rays_alloc_intersections_t(4);
    
    rays_intersections(intersections,4 , xs);
    intersect_t i;
    rays_hit(xs, &i);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, i4.t,      i.t);
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
    RUN_TEST(test_the_hit_when_all_intersections_have_negative_t);
    RUN_TEST(test_the_hit_when_all_intersections_all_negative_t);
    RUN_TEST(test_hit_is_lowest_nonnegative_intersection);

    return UNITY_END();
}