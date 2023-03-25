#include <unity.h>
#include <tuples.h>


void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}


void test_tuple_is_point(void) {
    vect3 v1 = {
        .x = 4.3f,
        .y = -4.2f,
        .z = 3.1f,
        .w = 1.0f
    };

    vect3 v2 = tuple(4.3f, -4.2f, 3.1f, 1.0f);
    
    TEST_ASSERT_EQUAL_FLOAT(v1.x, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(v1.y, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(v1.z, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(v1.w, v2.w);
}


void test_tuple_is_vector(void) {
    vect3 v1 = {
        .x = 4.3f,
        .y = -4.2f,
        .z = 3.1f,
        .w = 0.0f
    };

    vect3 v2 = tuple(4.3f, -4.2f, 3.1f, 0.0f);

    TEST_ASSERT_EQUAL_FLOAT(v1.x, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(v1.y, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(v1.z, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(v1.w, v2.w);
}


void test_point(void){
    vect3 p1 = {
        .x = 4.0f,
        .y = -4.0f,
        .z = 3.0f,
        .w = 1.0f
    };

    vect3 p2 = point(4.0f, -4.0f, 3.0f);

    TEST_ASSERT_EQUAL_FLOAT(p1.x, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(p1.y, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(p1.z, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(p1.w, p2.w);
}


void test_vector(void){
    vect3 p1 = {
        .x = 4.0f,
        .y = -4.0f,
        .z = 3.0f,
        .w = 0.0f
    };

    vect3 p2 = vector(4.0f, -4.0f, 3.0f);

    TEST_ASSERT_EQUAL_FLOAT(p1.x, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(p1.y, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(p1.z, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(p1.w, p2.w);
}


void test_vect3_equal(void){
    vect3 p1 = {
        .x = 4.0f,
        .y = -4.0f,
        .z = 3.0f,
        .w = 0.0f
    };

    vect3 p2 = {
        .x = 4.0f,
        .y = -4.0f,
        .z = 3.0f,
        .w = 0.0f
    };

    TEST_ASSERT_TRUE(vect_equal(&p1, &p2));
}


void test_vect3_add_tuple(void){
    vect3 p = {
        .x = 3.0f,
        .y = -2.0f,
        .z = 5.0f,
        .w = 1.0f
    };

    vect3 v = {
        .x = -2.0f,
        .y = 3.0f,
        .z = 1.0f,
        .w = 0.0f
    };

    vect3 v1 = {
        .x = 1.0f, 
        .y = 1.0f,
        .z = 6.0f,
        .w = 1.0f
    };
    
    vect3 res = add_tuple(&p, &v);
    
    TEST_ASSERT_EQUAL_FLOAT(v1.x, res.x);
    TEST_ASSERT_EQUAL_FLOAT(v1.y, res.y);
    TEST_ASSERT_EQUAL_FLOAT(v1.z, res.z);
    TEST_ASSERT_EQUAL_FLOAT(v1.w, res.w);

}


void test_vect3_sub_two_points(void){
    vect3 p1 = point(3.0f, 2.0f, 1.0f);
  
    vect3 p2 = point(5.0f, 6.0f, 7.0f);

    vect3 v = vector(-2.0f, -4.0f, -6.0f);
    
    vect3 res = sub_two_tuples(&p1, &p2);
    
    TEST_ASSERT_EQUAL_FLOAT(v.x, res.x);
    TEST_ASSERT_EQUAL_FLOAT(v.y, res.y);
    TEST_ASSERT_EQUAL_FLOAT(v.z, res.z);
    TEST_ASSERT_EQUAL_FLOAT(v.w, res.w);

}


void test_vect3_sub_point_vector(void){
    vect3 p = point(3.0f, 2.0f, 1.0f);
  
    vect3 v1 = vector(5.0f, 6.0f, 7.0f);

    vect3 v2 = point(-2.0f, -4.0f, -6.0f);
    
    vect3 res = sub_two_tuples(&p, &v1);
    
    TEST_ASSERT_EQUAL_FLOAT(v2.x, res.x);
    TEST_ASSERT_EQUAL_FLOAT(v2.y, res.y);
    TEST_ASSERT_EQUAL_FLOAT(v2.z, res.z);
    TEST_ASSERT_EQUAL_FLOAT(v2.w, res.w);
}


void test_is_point(void){
    vect3 p = point(1.0f, 1.0f, 1.0f);
    bool res = is_point(&p);

    TEST_ASSERT_EQUAL(true, res);
    vect3 v = vector(1.0f, 1.0f, 1.0f);
    res = is_point(&v);
    TEST_ASSERT_EQUAL(false, res);
}


void test_is_vector(void){
    vect3 p = vector(1.0f, 1.0f, 1.0f);
    bool res = is_vector(&p);

    TEST_ASSERT_EQUAL(true, res);

    vect3 v = point(1.0f, 1.0f, 1.0f);
    res = is_vector(&v);
    TEST_ASSERT_EQUAL(false, res);
}


void test_negate(void){
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);

    vect3 v1 = negate(&t);
    vect3 t2 = tuple(-1.0f, 2.0f, -3.0f, 4.0f);

    TEST_ASSERT_EQUAL_FLOAT(t2.x, v1.x);
    TEST_ASSERT_EQUAL_FLOAT(t2.y, v1.y);
    TEST_ASSERT_EQUAL_FLOAT(t2.z, v1.z);
    TEST_ASSERT_EQUAL_FLOAT(t2.w, v1.w);
}


void test_scalar_mult(void){

    float s = 3.5f;
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);
    vect3 v = scalar_mult(s, &t);
    t = tuple(3.5f, -7.0f, 10.5f, -14.0f);
   
    TEST_ASSERT_EQUAL_FLOAT(t.x, v.x);
    TEST_ASSERT_EQUAL_FLOAT(t.y, v.y);
    TEST_ASSERT_EQUAL_FLOAT(t.z, v.z);
    TEST_ASSERT_EQUAL_FLOAT(t.w, v.w);
}


void test_mult_frac(void){

    float s = 0.5f;
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);
    vect3 v = scalar_mult(s, &t);
    t =  tuple(0.5f, -1.0f, 1.5f, -2.0f);
    
    TEST_ASSERT_EQUAL_FLOAT(t.x, v.x);
    TEST_ASSERT_EQUAL_FLOAT(t.y, v.y);
    TEST_ASSERT_EQUAL_FLOAT(t.z, v.z);
    TEST_ASSERT_EQUAL_FLOAT(t.w, v.w);
}


void test_scalar_div(void){
    float s = 2.0f;
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);
    vect3 v = scalar_div(s, &t);
    t = tuple(0.5f, -1.0f, 1.5f, -2.0f);

    TEST_ASSERT_EQUAL_FLOAT(t.x, v.x);
    TEST_ASSERT_EQUAL_FLOAT(t.y, v.y);
    TEST_ASSERT_EQUAL_FLOAT(t.z, v.z);
    TEST_ASSERT_EQUAL_FLOAT(t.w, v.w);
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_tuple_is_point);
    RUN_TEST(test_tuple_is_vector);
    RUN_TEST(test_point);
    RUN_TEST(test_vector);
    RUN_TEST(test_vect3_equal);
    RUN_TEST(test_vect3_add_tuple);
    RUN_TEST(test_vect3_sub_two_points);
    RUN_TEST(test_vect3_sub_point_vector);
    RUN_TEST(test_is_point);
    RUN_TEST(test_is_vector);
    RUN_TEST(test_negate);
    RUN_TEST(test_scalar_mult);
    RUN_TEST(test_mult_frac);
    RUN_TEST(test_scalar_div);

    return UNITY_END();
}