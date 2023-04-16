#include <unity.h>
#include <stdlib.h>
#include <tuples.h>
#include <canvas.h>
#include <rays.h>
#include <transformations.h>
#include <matrices.h>
#include <spheres.h>

void setUp(void) {
    
}

void tearDown(void) {
    // clean stuff up here
}

void test_sphere_default_transformation(void){
    sphere_t s = sphere();

    matrix4 I;
    matrix4_get_identity(I);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(I[0], s.transform[0], 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(I[1], s.transform[1], 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(I[2], s.transform[2], 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(I[3], s.transform[3], 4);
}

void test_change_sphere_transform(void){
    sphere_t s = sphere();

    matrix4 T;
    transformation_get_translate(2.0, 3.0, 4.0, T);
    sphere_set_transform(&s, T);

    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(T[0], s.transform[0], 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(T[1], s.transform[1], 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(T[2], s.transform[2], 4);
    TEST_ASSERT_EQUAL_DOUBLE_ARRAY(T[3], s.transform[3], 4);
}

void test_intersecting_a_scaled_sphere_with_ray(void){
    point4 p;
    point(0.0, 0.0, -5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);

    sphere_t s = sphere();
    matrix4 T;
    transformation_get_scaling(2.0, 2.0, 2.0, T);
    sphere_set_transform(&s, T);
    intersections_t *xs = rays_alloc_intersections_t(2);
    sphere_intersect(&s, &r, xs);

    TEST_ASSERT_EQUAL_DOUBLE(2, xs->count);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, xs->xs[0].t);
    TEST_ASSERT_EQUAL_DOUBLE(7.0, xs->xs[1].t);
    free(xs);
}

void test_intersectint_translated_sphere_with_ray(void){
    point4 p;
    point(0.0, 0.0, -5.0, p);
    vect4 v;
    vector(0.0, 0.0, 1.0, v);
    ray_t r = ray(p, v);

    sphere_t s = sphere();
    matrix4 T;
    transformation_get_translate(5.0, 0.0, 0.0, T);
    sphere_set_transform(&s, T);
    intersections_t xs;
    sphere_intersect(&s, &r, &xs);

    TEST_ASSERT_EQUAL_DOUBLE(0.0, xs.count);

}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sphere_default_transformation);
    RUN_TEST(test_change_sphere_transform);
    RUN_TEST(test_intersecting_a_scaled_sphere_with_ray);
    RUN_TEST(test_intersectint_translated_sphere_with_ray);
    return UNITY_END();
}