#include <unity.h>
#include <stdlib.h>
#include <matrices.h>
#include <tuples.c>
#include <transformations.h>
#include <math.h>
#include <spheres.h>
void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}

void test_matrix4_get_transform(void){
    matrix4 trans = {0};
    transformation_get_translate(5.0, -3.0, 2.0, trans);

    vect4 p = {0};
    point(-3.0, 4.0, 5.0, p);
    
    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_EQUAL_DOUBLE(2.0, res[X]);
    TEST_ASSERT_EQUAL_DOUBLE(1.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(7.0, res[Z]);
}

void test_matrix4_get_transform_mult_inv(void){
    matrix4 trans = {0};
    transformation_get_translate(5.0, -3.0, 2.0, trans);

    matrix4 inv = {0};
    matrix4_inverse(trans, inv);
    vect4 p = {0};
    point(-3.0, 4.0, 5.0, p);
    
    vect4 res = {0};
    matrix4_vect3_mult(inv, p, res);

    TEST_ASSERT_EQUAL_DOUBLE(-8.0, res[X]);
    TEST_ASSERT_EQUAL_DOUBLE( 7.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 3.0, res[Z]);
}

void test_matrix4_get_transform_mult_vect(void){

    matrix4 trans = {0};
    transformation_get_translate(5.0, -3.0, 2.0, trans);

    vect4 v = {0};
    vector(-3.0, 4.0, 5.0, v);
    
    vect4 res = {0};
    matrix4_vect3_mult(trans, v, res);

    TEST_ASSERT_EQUAL_DOUBLE(-3.0, res[X]);
    TEST_ASSERT_EQUAL_DOUBLE( 4.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 5.0, res[Z]);
}

void test_matrix4_scaling_point(void){
    matrix4 scale = {0};
    transformation_get_scaling(2.0, 3.0, 4.0, scale);

    vect4 p = {0};
    point(-4.0, 6.0, 8.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(scale, p, res);

    TEST_ASSERT_EQUAL_DOUBLE(-8.0,  res[X]);
    TEST_ASSERT_EQUAL_DOUBLE( 18.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 32.0, res[Z]);
}

void test_matrix4_scaling_vector(void){
    matrix4 scale = {0};
    transformation_get_scaling(2.0, 3.0, 4.0, scale);

    vect4 v = {0};
    vector(-4.0, 6.0, 8.0, v);

    vect4 res = {0};
    matrix4_vect3_mult(scale, v, res);

    TEST_ASSERT_EQUAL_DOUBLE(-8.0,  res[X]);
    TEST_ASSERT_EQUAL_DOUBLE( 18.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 32.0, res[Z]);
}

void test_matrix4_scale_inverse_vector(void){
    matrix4 scale = {0};
    transformation_get_scaling(2.0, 3.0, 4.0, scale);

    matrix4 inv = {0};
    bool invertible = matrix4_inverse(scale, inv);
    TEST_ASSERT_TRUE(invertible);


    vect4 v = {0};
    vector(-4.0, 6.0, 8.0, v);

    vect4 res = {0};
    matrix4_vect3_mult(inv, v, res);

    TEST_ASSERT_EQUAL_DOUBLE(-2.0, res[X]);
    TEST_ASSERT_EQUAL_DOUBLE( 2.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 2.0, res[Z]);
}

void test_matrix4_scaling_point_reflect(void){
    matrix4 trans = {0};
    transformation_get_scaling(-1, 1, 1, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_EQUAL_DOUBLE(-2.0, res[X]);
    TEST_ASSERT_EQUAL_DOUBLE( 3.0, res[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 4.0, res[Z]);
}

void test_rot_x(void){
    vect4 p = {0};
    point(0.0, 1.0, 0.0, p);

    matrix4 half_quarter = {0};
  
    transformation_get_rotx(M_PI/4.0, half_quarter);

    vect4 res1 = {0};
    matrix4_vect3_mult(half_quarter, p, res1);

    TEST_ASSERT_EQUAL_DOUBLE(0.0,           res1[X]);
    TEST_ASSERT_EQUAL_DOUBLE(sqrt(2.0)/2,   res1[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(sqrt(2.0)/2,   res1[Z]);

    matrix4 full_quarter = {0};
    transformation_get_rotx(M_PI/2.0, full_quarter);

    vect4 res2 = {0};
    matrix4_vect3_mult(full_quarter, p, res2);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 0.0, res2[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 0.0, res2[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 1.0, res2[Z]);
}

void test_rotx_inv(void){
    vect4 p = {0};
    point(0.0, 1.0, 0.0, p);

    matrix4 half_quarter = {0};
    transformation_get_rotx(M_PI/4, half_quarter);

    matrix4 inv = {0};
    matrix4_inverse(half_quarter, inv);

    vect4 res = {0};
    matrix4_vect3_mult(inv, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 0.0,            res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, sqrt(2.0)/2.0,  res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, -sqrt(2.0)/2.0, res[Z]);
}

void test_rot_y(void){
    vect4 p = {0};
    point(0.0, 0.0, 1.0, p);

    matrix4 half_quarter = {0};
  
    transformation_get_roty(M_PI/4.0, half_quarter);

    vect4 res1 = {0};
    matrix4_vect3_mult(half_quarter, p, res1);

    TEST_ASSERT_EQUAL_DOUBLE(sqrt(2.0)/2,   res1[X]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0,           res1[Y]);
    TEST_ASSERT_EQUAL_DOUBLE(sqrt(2.0)/2,   res1[Z]);

    matrix4 full_quarter = {0};
    transformation_get_roty(M_PI/2.0, full_quarter);

    vect4 res2 = {0};
    matrix4_vect3_mult(full_quarter, p, res2);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 1.0, res2[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 0.0, res2[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, 0.0, res2[Z]);
}

void test_rot_z(void){
    vect4 p = {0};
    point(0.0, 1.0, 0.0, p);

    matrix4 half_quarter = {0};
  
    transformation_get_rotz(M_PI/4.0, half_quarter);

    vect4 res1 = {0};
    matrix4_vect3_mult(half_quarter, p, res1);

    TEST_ASSERT_EQUAL_DOUBLE(-sqrt(2.0)/2, res1[X]);
    TEST_ASSERT_EQUAL_DOUBLE( sqrt(2.0)/2, res1[Y]);
    TEST_ASSERT_EQUAL_DOUBLE( 0.0,         res1[Z]);

    matrix4 full_quarter = {0};
    transformation_get_rotz(M_PI/2.0, full_quarter);

    vect4 res2 = {0};
    matrix4_vect3_mult(full_quarter, p, res2);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON, -1.0, res2[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  0.0, res2[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  0.0, res2[Z]);
}

void test_shear_x_y(void){
    matrix4 trans = {0};
    transformation_get_shearing(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  5.0, res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  3.0, res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  4.0, res[Z]);

}

void test_shear_x_z(void){
    matrix4 trans = {0};
    transformation_get_shearing(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  6.0, res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  3.0, res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  4.0, res[Z]);

}

void test_shear_y_z(void){
    matrix4 trans = {0};
    transformation_get_shearing(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  2.0, res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  5.0, res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  4.0, res[Z]);

}

void test_shear_y_x(void){
    matrix4 trans = {0};
    transformation_get_shearing(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  2.0, res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  7.0, res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  4.0, res[Z]);

}

void test_shear_z_x(void){
    matrix4 trans = {0};
    transformation_get_shearing(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  2.0, res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  3.0, res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  6.0, res[Z]);

}

void test_shear_z_y(void){
    matrix4 trans = {0};
    transformation_get_shearing(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, trans);

    vect4 p = {0};
    point(2.0, 3.0, 4.0, p);

    vect4 res = {0};
    matrix4_vect3_mult(trans, p, res);

    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  2.0, res[X]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  3.0, res[Y]);
    TEST_ASSERT_DOUBLE_WITHIN(EPSILON,  7.0, res[Z]);
}

void test_transforms_in_sequence(void){
    vect4 p = {0};
    point(1.0, 0.0, 1.0, p);

    matrix4 A = {0};
    transformation_get_rotx(M_PI/2.0, A);

    matrix4 B = {0};
    transformation_get_scaling(5.0, 5.0, 5.0, B);

    matrix4 C = {0};
    transformation_get_translate(10.0, 5.0, 7.0, C);

    
    
    vect4 p2 = {0};
    matrix4_vect3_mult(A, p, p2);
    vect4 test = {0};
    point(1.0, -1.0, 0.0, test);
    TEST_ASSERT_DOUBLE_ARRAY_WITHIN(EPSILON, test, p2, 4);

    
    vect4 p3 = {0};
    matrix4_vect3_mult(B, p2, p3);
    point(5.0, -5.0, 0.0, test);
    TEST_ASSERT_DOUBLE_ARRAY_WITHIN(EPSILON, test, p3, 4);

    vect4 p4 = {0};
    matrix4_vect3_mult(C, p3, p4);
    point(15.0, 0.0, 7.0, test);
    TEST_ASSERT_DOUBLE_ARRAY_WITHIN(EPSILON, test, p4, 4);
}

void test_chained_transforms(void){
    vect4 p = {0};
    point(1.0, 0.0, 1.0, p);

    matrix4 A = {0};
    transformation_get_rotx(M_PI/2.0, A);

    matrix4 B = {0};
    transformation_get_scaling(5.0, 5.0, 5.0, B);

    matrix4 C = {0};
    transformation_get_translate(10.0, 5.0, 7.0, C);

    matrix4 temp = {0};
    matrix4_mult(C, B, temp);
    matrix4 T = {0};
    matrix4_mult(temp, A, T);

    vect4 p2 = {0};
    matrix4_vect3_mult(T, p, p2);

    vect4 test = {0};
    point(15.0, 0.0, 7.0, test);
    TEST_ASSERT_DOUBLE_ARRAY_WITHIN(EPSILON, test, p2, 4);

}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_matrix4_get_transform);
    RUN_TEST(test_matrix4_get_transform_mult_inv);
    RUN_TEST(test_matrix4_get_transform_mult_vect);
    RUN_TEST(test_matrix4_scaling_point);
    RUN_TEST(test_matrix4_scaling_vector);
    RUN_TEST(test_matrix4_scale_inverse_vector);
    RUN_TEST(test_matrix4_scaling_point);
    RUN_TEST(test_matrix4_scaling_point_reflect);
    RUN_TEST(test_rot_x);
    RUN_TEST(test_rotx_inv);
    RUN_TEST(test_rot_y);
    RUN_TEST(test_rot_z);
    RUN_TEST(test_shear_x_y);
    RUN_TEST(test_shear_x_z);
    RUN_TEST(test_shear_y_x);
    RUN_TEST(test_shear_y_z);
    RUN_TEST(test_shear_z_x);
    RUN_TEST(test_shear_z_y);
    RUN_TEST(test_transforms_in_sequence);
    RUN_TEST(test_chained_transforms);
    return UNITY_END();
}