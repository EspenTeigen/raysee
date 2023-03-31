#include <unity.h>
#include <tuples.h>

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}


void test_tuple_is_point(void) {
    
    vect3 v2 = tuple(4.3, -4.2, 3.1, 1.0);
    
    TEST_ASSERT_EQUAL_FLOAT(4.3, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.2, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.1, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0, v2.w);
}


void test_tuple_is_vector(void) {
 
    vect3 v2 = tuple(4.3, -4.2, 3.1, 0.0);

    TEST_ASSERT_EQUAL_FLOAT(4.3, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.2, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.1, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(0.0, v2.w);
}


void test_point(void){

    vect3 p2 = point(4.0, -4.0, 3.0);

    TEST_ASSERT_EQUAL_FLOAT(4.0, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.0, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0, p2.w);
}


void test_vector(void){

    vect3 p2 = vector(4.0, -4.0, 3.0);

    TEST_ASSERT_EQUAL_FLOAT(4.0, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.0, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(0.0, p2.w);
}


void test_vect3_equal(void){
    vect3 p1 = {
        .x = 4.0,
        .y = -4.0,
        .z = 3.0,
        .w = 0.0
    };

    vect3 p2 = {
        .x = 4.0,
        .y = -4.0,
        .z = 3.0,
        .w = 0.0
    };

    TEST_ASSERT_TRUE(tuple_equal(&p1, &p2));
}


void test_vect3_add_tuple(void){
    vect3 p = {
        .x = 3.0,
        .y = -2.0,
        .z = 5.0,
        .w = 1.0
    };

    vect3 v = {
        .x = -2.0,
        .y = 3.0,
        .z = 1.0,
        .w = 0.0
    };

    vect3 res = add_tuple(&p, &v);
    
    TEST_ASSERT_EQUAL_FLOAT(1.0, res.x);
    TEST_ASSERT_EQUAL_FLOAT(1.0, res.y);
    TEST_ASSERT_EQUAL_FLOAT(6.0, res.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0, res.w);
}


void test_vect3_sub_two_points(void){
    vect3 p1 = point(3.0, 2.0, 1.0);
  
    vect3 p2 = point(5.0, 6.0, 7.0);

    vect3 res = sub_two_tuples(&p1, &p2);
    
    TEST_ASSERT_EQUAL_FLOAT(-2.0, res.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, res.y);
    TEST_ASSERT_EQUAL_FLOAT(-6.0, res.z);
    TEST_ASSERT_EQUAL_FLOAT(0.0, res.w);

}


void test_vect3_sub_point_vector(void){
    vect3 p = point(3.0, 2.0, 1.0);
  
    vect3 v1 = vector(5.0, 6.0, 7.0);

    vect3 res = sub_two_tuples(&p, &v1);
    
    TEST_ASSERT_EQUAL_FLOAT(-2.0, res.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, res.y);
    TEST_ASSERT_EQUAL_FLOAT(-6.0, res.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0, res.w);
}


void test_is_point(void){
    vect3 p = point(1.0, 1.0, 1.0);
    bool res = is_point(&p);

    TEST_ASSERT_EQUAL(true, res);
    vect3 v = vector(1.0, 1.0, 1.0);
    res = is_point(&v);
    TEST_ASSERT_EQUAL(false, res);
}


void test_is_vector(void){
    vect3 p = vector(1.0, 1.0, 1.0);
    bool res = is_vector(&p);

    TEST_ASSERT_EQUAL(true, res);

    vect3 v = point(1.0, 1.0, 1.0);
    res = is_vector(&v);
    TEST_ASSERT_EQUAL(false, res);
}


void test_negate(void){
    vect3 t = tuple(1.0, -2.0, 3.0, -4.0);
    vect3 v1 = negate(&t);
  
    TEST_ASSERT_EQUAL_FLOAT(-1.0, v1.x);
    TEST_ASSERT_EQUAL_FLOAT(2.0, v1.y);
    TEST_ASSERT_EQUAL_FLOAT(-3.0, v1.z);
    TEST_ASSERT_EQUAL_FLOAT(4.0, v1.w);
}


void test_scalar_mult(void){

    float s = 3.5f;
    vect3 t = tuple(1.0, -2.0, 3.0, -4.0);
    vect3 v = scalar_mult(s, &t);
   
    TEST_ASSERT_EQUAL_FLOAT(3.5, v.x);
    TEST_ASSERT_EQUAL_FLOAT(-7.0, v.y);
    TEST_ASSERT_EQUAL_FLOAT(10.5, v.z);
    TEST_ASSERT_EQUAL_FLOAT(-14.0, v.w);
}


void test_mult_frac(void){

    float s = 0.5;
    vect3 t = tuple(1.0, -2.0, 3.0, -4.0);
    vect3 v = scalar_mult(s, &t);
    
    TEST_ASSERT_EQUAL_FLOAT(0.5, v.x);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, v.y);
    TEST_ASSERT_EQUAL_FLOAT(1.5, v.z);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, v.w);
}


void test_scalar_div(void){
    float s = 2.0;
    vect3 t = tuple(1.0, -2.0, 3.0, -4.0);
    vect3 v = scalar_div(s, &t);

    TEST_ASSERT_EQUAL_FLOAT(0.5, v.x);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, v.y);
    TEST_ASSERT_EQUAL_FLOAT(1.5, v.z);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, v.w);
}


void test_magnitude(void){
    vect3 v1 = vector(1.0, 0.0, 0.0);
    vect3 v2 = vector(0.0, 1.0, 0.0);
    vect3 v3 = vector(0.0, 0.0, 1.0);
    vect3 v4 = vector(1.0, 2.0, 3.0);
    vect3 v5 = vector(-1.0, -2.0, -3.0);
    float mag1 = mag(&v1);
    float mag2 = mag(&v2);
    float mag3 = mag(&v3);
    float mag4 = mag(&v4);
    float mag5 = mag(&v5);


    TEST_ASSERT_EQUAL_FLOAT(1.0, mag1);
    TEST_ASSERT_EQUAL_FLOAT(1.0, mag2);
    TEST_ASSERT_EQUAL_FLOAT(1.0, mag3);
    TEST_ASSERT_EQUAL_FLOAT((float)sqrt(14.0), mag4);
    TEST_ASSERT_EQUAL_FLOAT((float)sqrt(14.0), mag5);
}

void test_norm(void){
    vect3 v = vector(4.0, 0.0, 0.0);
    vect3 normalized = norm(&v);
    
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 1.0, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.0, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.0, normalized.z);

    v = vector(1.0f ,2.0f ,3.0f);
    normalized = norm(&v);

    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.26726, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.53452, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.80178, normalized.z);
}

void test_dot(void){
    vect3 v1 = vector(1.0, 2.0, 3.0);
    vect3 v2 = vector(2.0, 3.0, 4.0);

    float d = dot_p(&v1, &v2);

   TEST_ASSERT_EQUAL_FLOAT(20.0, d);
}

void test_cross(void){
    vect3 v1 = vector(1.0, 2.0, 3.0);
    vect3 v2 = vector(2.0, 3.0, 4.0);

    vect3 c1 = cross_p(&v1, &v2);
    vect3 c2 = cross_p(&v2, &v1);

    TEST_ASSERT_EQUAL_FLOAT(-1.0, c1.x);
    TEST_ASSERT_EQUAL_FLOAT(2.0, c1.y);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, c1.z);

    TEST_ASSERT_EQUAL_FLOAT(1.0, c2.x);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, c2.y);
    TEST_ASSERT_EQUAL_FLOAT(1.0, c2.z);
}

void test_color_create(void){
    color_t c1 = color_create(-0.5, 0.4, 1.7);

    TEST_ASSERT_EQUAL_FLOAT(-0.5, c1.r);
    TEST_ASSERT_EQUAL_FLOAT(0.4, c1.g);
    TEST_ASSERT_EQUAL_FLOAT(1.7, c1.b);
}

void test_color_add(void){
    color_t c1 = color_create(0.9, 0.6, 0.75);
    color_t c2 = color_create(0.7, 0.1, 0.25);
  
    color_t c4 = color_add(&c1, &c2);

    TEST_ASSERT_EQUAL_FLOAT(1.6, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.7, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(1.0, c4.b);
}

void test_color_sub(void){
    color_t c1 = color_create(0.9, 0.6, 0.75);
    color_t c2 = color_create(0.7, 0.1, 0.25);
  
    color_t c4 = color_sub(&c1, &c2);

    TEST_ASSERT_EQUAL_FLOAT(0.2, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.5, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.5, c4.b);
}

void test_color__scalar_mult(void){
    color_t c = color_create(0.2, 0.3, 0.4);
    float scalar = 2.0;
  
    color_t c4 = color_scalar_mult(scalar, &c);

    TEST_ASSERT_EQUAL_FLOAT(0.4, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.6, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.8, c4.b);
}

void test_color_mult(void){
    color_t c1 = color_create(1.f, 0.2, 0.4f);
    color_t c2 = color_create(0.9, 1.0, 0.1f);
  
    color_t c4 = color_mult(&c1, &c2);

    TEST_ASSERT_EQUAL_FLOAT(0.9, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.2, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.04, c4.b);
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
    RUN_TEST(test_magnitude);
    RUN_TEST(test_norm);
    RUN_TEST(test_dot);
    RUN_TEST(test_cross);
    RUN_TEST(test_color_create);
    RUN_TEST(test_color_add);
    RUN_TEST(test_color_sub);
    RUN_TEST(test_color__scalar_mult);
    RUN_TEST(test_color_mult);
    return UNITY_END();
}