#include <unity.h>
#include <tuples.h>

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}


void test_tuple_is_point(void) {
    
    vect4 v2;
    tuple(4.3, -4.2, 3.1, 1.0, v2);
    
    TEST_ASSERT_EQUAL_FLOAT(4.3,  v2[X]);
    TEST_ASSERT_EQUAL_FLOAT(-4.2, v2[Y]);
    TEST_ASSERT_EQUAL_FLOAT(3.1,  v2[Z]);
    TEST_ASSERT_EQUAL_FLOAT(1.0,  v2[W]);
}


void test_tuple_is_vector(void) {
 
    vect4 v2;
    tuple(4.3, -4.2, 3.1, 0.0, v2);

    TEST_ASSERT_EQUAL_FLOAT(4.3,  v2[X]);
    TEST_ASSERT_EQUAL_FLOAT(-4.2, v2[Y]);
    TEST_ASSERT_EQUAL_FLOAT(3.1,  v2[Z]);
    TEST_ASSERT_EQUAL_FLOAT(0.0,  v2[W]);
}


void test_point(void){

    vect4 p2;
    point(4.0, -4.0, 3.0, p2);

    TEST_ASSERT_EQUAL_FLOAT(4.0,  p2[X]);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, p2[Y]);
    TEST_ASSERT_EQUAL_FLOAT(3.0,  p2[Z]);
    TEST_ASSERT_EQUAL_FLOAT(1.0,  p2[W]);
}


void test_vector(void){

    vect4 p2;
    vector(4.0, -4.0, 3.0, p2);

    TEST_ASSERT_EQUAL_FLOAT(4.0,  p2[X]);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, p2[Y]);
    TEST_ASSERT_EQUAL_FLOAT(3.0,  p2[Z]);
    TEST_ASSERT_EQUAL_FLOAT(0.0,  p2[W]);
}


void test_vect3_equal(void){
    vect4 p1 = {
        4.0,
        -4.0,
        3.0,
        0.0
    };

    vect4 p2 = {
        4.0,
        -4.0,
        3.0,
        0.0
    };

    TEST_ASSERT_TRUE(tuple_equal(p1, p2));
}


void test_vect3_add_tuple(void){
    vect4 p = {
        3.0,
        -2.0,
        5.0,
        1.0
    };

    vect4 v = {
        -2.0,
        3.0,
        1.0,
        0.0
    };

    vect4 res;
    add_tuple(p, v, res);
    
    TEST_ASSERT_EQUAL_FLOAT(1.0, res[X]);
    TEST_ASSERT_EQUAL_FLOAT(1.0, res[Y]);
    TEST_ASSERT_EQUAL_FLOAT(6.0, res[Z]);
    TEST_ASSERT_EQUAL_FLOAT(1.0, res[W]);
}


void test_vect3_sub_two_points(void){
    vect4 p1;
    point(3.0, 2.0, 1.0, p1);
  
    vect4 p2;
    point(5.0, 6.0, 7.0, p2);
    
    vect4 res;
    sub_two_tuples(p1, p2, res);
    
    TEST_ASSERT_EQUAL_FLOAT(-2.0, res[X]);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, res[Y]);
    TEST_ASSERT_EQUAL_FLOAT(-6.0, res[Z]);
    TEST_ASSERT_EQUAL_FLOAT(0.0,  res[W]);

}


void test_vect3_sub_point_vector(void){
    vect4 p;
    point(3.0, 2.0, 1.0, p);
  
    vect4 v1;
    vector(5.0, 6.0, 7.0, v1);

    vect4 res;
    sub_two_tuples(p, v1, res);
    
    TEST_ASSERT_EQUAL_FLOAT(-2.0, res[X]);
    TEST_ASSERT_EQUAL_FLOAT(-4.0, res[Y]);
    TEST_ASSERT_EQUAL_FLOAT(-6.0, res[Z]);
    TEST_ASSERT_EQUAL_FLOAT(1.0,  res[W]);
}


void test_is_point(void){
    vect4 p;
    point(1.0, 1.0, 1.0, p);
    bool res = is_point(p);

    TEST_ASSERT_EQUAL(true, res);

    vect4 v;
    vector(1.0, 1.0, 1.0, v);

    res = is_point(v);
    TEST_ASSERT_EQUAL(false, res);
}


void test_is_vector(void){
    vect4 p;
    vector(1.0, 1.0, 1.0, p);
    bool res = is_vector(p);

    TEST_ASSERT_EQUAL(true, res);

    vect4 v;
    point(1.0, 1.0, 1.0, v);
    res = is_vector(v);
    TEST_ASSERT_EQUAL(false, res);
}


void test_negate(void){
    vect4 t;
    tuple(1.0, -2.0, 3.0, -4.0, t);
    negate(t, t);
  
    TEST_ASSERT_EQUAL_FLOAT(-1.0, t[X]);
    TEST_ASSERT_EQUAL_FLOAT(2.0,  t[Y]);
    TEST_ASSERT_EQUAL_FLOAT(-3.0, t[Z]);
    TEST_ASSERT_EQUAL_FLOAT(4.0,  t[W]);
}


void test_scalar_mult(void){

    float s = 3.5f;
    vect4 t;
    tuple(1.0, -2.0, 3.0, -4.0, t);
    
    vect4 v;
    scalar_mult(s, t, v);
   
    TEST_ASSERT_EQUAL_FLOAT(3.5,   v[X]);
    TEST_ASSERT_EQUAL_FLOAT(-7.0,  v[Y]);
    TEST_ASSERT_EQUAL_FLOAT(10.5,  v[Z]);
    TEST_ASSERT_EQUAL_FLOAT(-14.0, v[W]);
}


void test_mult_frac(void){

    float s = 0.5;
    vect4 t;
    tuple(1.0, -2.0, 3.0, -4.0, t);
    vect4 v;
    scalar_mult(s, t, v);
    
    TEST_ASSERT_EQUAL_FLOAT(0.5,  v[X]);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, v[Y]);
    TEST_ASSERT_EQUAL_FLOAT(1.5,  v[Z]);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, v[W]);
}


void test_scalar_div(void){
    float s = 2.0;
    vect4 t;
    tuple(1.0, -2.0, 3.0, -4.0, t);

    vect4 v;
    scalar_div(s, t, v);

    TEST_ASSERT_EQUAL_FLOAT(0.5,  v[X]);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, v[Y]);
    TEST_ASSERT_EQUAL_FLOAT(1.5,  v[Z]);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, v[W]);
}


void test_magnitude(void){
    vect4 v1;
    vector(1.0, 0.0, 0.0, v1);

    vect4 v2;
    vector(0.0, 1.0, 0.0, v2);

    vect4 v3;
    vector(0.0, 0.0, 1.0, v3);

    vect4 v4;
    vector(1.0, 2.0, 3.0, v4);

    vect4 v5;
    vector(-1.0, -2.0, -3.0, v5);
    float mag1 = mag(v1);
    float mag2 = mag(v2);
    float mag3 = mag(v3);
    float mag4 = mag(v4);
    float mag5 = mag(v5);

    TEST_ASSERT_EQUAL_FLOAT(1.0, mag1);
    TEST_ASSERT_EQUAL_FLOAT(1.0, mag2);
    TEST_ASSERT_EQUAL_FLOAT(1.0, mag3);
    TEST_ASSERT_EQUAL_FLOAT((float)sqrt(14.0), mag4);
    TEST_ASSERT_EQUAL_FLOAT((float)sqrt(14.0), mag5);
}

void test_norm(void){
    vect4 v;
    vector(4.0, 0.0, 0.0, v);

    vect4 normalized;
    norm(v, normalized);
    
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 1.0, normalized[X]);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.0, normalized[Y]);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.0, normalized[Z]);

    vector(1.0f ,2.0f ,3.0f, v);
    
    norm(v, normalized);

    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.26726, normalized[X]);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.53452, normalized[Y]);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.80178, normalized[Z]);
}

void test_dot(void){
    vect4 v1;
    vector(1.0, 2.0, 3.0, v1);

    vect4 v2;
    vector(2.0, 3.0, 4.0, v2);

    float d = dot_p(v1, v2);

   TEST_ASSERT_EQUAL_FLOAT(20.0, d);
}

void test_cross(void){
    vect4 v1;
    vector(1.0, 2.0, 3.0, v1);

    vect4 v2; 
    vector(2.0, 3.0, 4.0, v2);

    vect4 c1;
    cross_p(v1, v2, c1);

    vect4 c2;
    cross_p(v2, v1, c2);

    TEST_ASSERT_EQUAL_FLOAT(-1.0, c1[X]);
    TEST_ASSERT_EQUAL_FLOAT(2.0,  c1[Y]);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, c1[Z]);

    TEST_ASSERT_EQUAL_FLOAT(1.0,  c2[X]);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, c2[Y]);
    TEST_ASSERT_EQUAL_FLOAT(1.0,  c2[Z]);
}

void test_color_create(void){
    color_t c1;
    color_create(-0.5, 0.4, 1.7, &c1);

    TEST_ASSERT_EQUAL_FLOAT(-0.5, c1.r);
    TEST_ASSERT_EQUAL_FLOAT(0.4, c1.g);
    TEST_ASSERT_EQUAL_FLOAT(1.7, c1.b);
}

void test_color_add(void){
    color_t c1;
    color_create(0.9, 0.6, 0.75, &c1);
    
    color_t c2;
    color_create(0.7, 0.1, 0.25, &c2);
  
    color_t c4;
    color_add(&c1, &c2, &c4);

    TEST_ASSERT_EQUAL_FLOAT(1.6, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.7, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(1.0, c4.b);
}

void test_color_sub(void){
    color_t c1;
    color_create(0.9, 0.6, 0.75, &c1);

    color_t c2;
    color_create(0.7, 0.1, 0.25, &c2);
  
    color_t c4;
    color_sub(&c1, &c2, &c4);

    TEST_ASSERT_EQUAL_FLOAT(0.2, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.5, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.5, c4.b);
}

void test_color__scalar_mult(void){
    color_t c;
    color_create(0.2, 0.3, 0.4, &c);
    float scalar = 2.0;
  
    color_t c4;
    color_scalar_mult(scalar, &c, &c4);

    TEST_ASSERT_EQUAL_FLOAT(0.4, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.6, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.8, c4.b);
}

void test_color_mult(void){
    color_t c1;
    color_create(1.f, 0.2, 0.4f, &c1);

    color_t c2;
    color_create(0.9, 1.0, 0.1f, &c2);
  
    color_t c4;
    color_mult(&c1, &c2, &c4);

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