#include <unity.h>
#include <tuples.h>
#include <canvas.h>

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}


void test_tuple_is_point(void) {
    
    vect3 v2 = tuple(4.3f, -4.2f, 3.1f, 1.0f);
    
    TEST_ASSERT_EQUAL_FLOAT(4.3f, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.2f, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.1f, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, v2.w);
}


void test_tuple_is_vector(void) {
 
    vect3 v2 = tuple(4.3f, -4.2f, 3.1f, 0.0f);

    TEST_ASSERT_EQUAL_FLOAT(4.3f, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.2f, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.1f, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, v2.w);
}


void test_point(void){

    vect3 p2 = point(4.0f, -4.0f, 3.0f);

    TEST_ASSERT_EQUAL_FLOAT(4.0f, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0f, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.0f, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, p2.w);
}


void test_vector(void){

    vect3 p2 = vector(4.0f, -4.0f, 3.0f);

    TEST_ASSERT_EQUAL_FLOAT(4.0f, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0f, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(3.0f, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, p2.w);
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

    TEST_ASSERT_TRUE(tuple_equal(&p1, &p2));
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

    vect3 res = add_tuple(&p, &v);
    
    TEST_ASSERT_EQUAL_FLOAT(1.0f, res.x);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, res.y);
    TEST_ASSERT_EQUAL_FLOAT(6.0f, res.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, res.w);
}


void test_vect3_sub_two_points(void){
    vect3 p1 = point(3.0f, 2.0f, 1.0f);
  
    vect3 p2 = point(5.0f, 6.0f, 7.0f);

    vect3 res = sub_two_tuples(&p1, &p2);
    
    TEST_ASSERT_EQUAL_FLOAT(-2.0f, res.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0f, res.y);
    TEST_ASSERT_EQUAL_FLOAT(-6.0f, res.z);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, res.w);

}


void test_vect3_sub_point_vector(void){
    vect3 p = point(3.0f, 2.0f, 1.0f);
  
    vect3 v1 = vector(5.0f, 6.0f, 7.0f);

    vect3 res = sub_two_tuples(&p, &v1);
    
    TEST_ASSERT_EQUAL_FLOAT(-2.0f, res.x);
    TEST_ASSERT_EQUAL_FLOAT(-4.0f, res.y);
    TEST_ASSERT_EQUAL_FLOAT(-6.0f, res.z);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, res.w);
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
  
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, v1.x);
    TEST_ASSERT_EQUAL_FLOAT(2.0f, v1.y);
    TEST_ASSERT_EQUAL_FLOAT(-3.0f, v1.z);
    TEST_ASSERT_EQUAL_FLOAT(4.0f, v1.w);
}


void test_scalar_mult(void){

    float s = 3.5f;
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);
    vect3 v = scalar_mult(s, &t);
   
    TEST_ASSERT_EQUAL_FLOAT(3.5f, v.x);
    TEST_ASSERT_EQUAL_FLOAT(-7.0f, v.y);
    TEST_ASSERT_EQUAL_FLOAT(10.5f, v.z);
    TEST_ASSERT_EQUAL_FLOAT(-14.0f, v.w);
}


void test_mult_frac(void){

    float s = 0.5f;
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);
    vect3 v = scalar_mult(s, &t);
    
    TEST_ASSERT_EQUAL_FLOAT(0.5f, v.x);
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, v.y);
    TEST_ASSERT_EQUAL_FLOAT(1.5f, v.z);
    TEST_ASSERT_EQUAL_FLOAT(-2.0f, v.w);
}


void test_scalar_div(void){
    float s = 2.0f;
    vect3 t = tuple(1.0f, -2.0f, 3.0f, -4.0f);
    vect3 v = scalar_div(s, &t);

    TEST_ASSERT_EQUAL_FLOAT(0.5f, v.x);
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, v.y);
    TEST_ASSERT_EQUAL_FLOAT(1.5f, v.z);
    TEST_ASSERT_EQUAL_FLOAT(-2.0f, v.w);
}


void test_magnitude(void){
    vect3 v1 = vector(1.0f, 0.0f, 0.0f);
    vect3 v2 = vector(0.0f, 1.0f, 0.0f);
    vect3 v3 = vector(0.0f, 0.0f, 1.0f);
    vect3 v4 = vector(1.0f, 2.0f, 3.0f);
    vect3 v5 = vector(-1.0f, -2.0f, -3.0f);
    float mag1 = mag(&v1);
    float mag2 = mag(&v2);
    float mag3 = mag(&v3);
    float mag4 = mag(&v4);
    float mag5 = mag(&v5);


    TEST_ASSERT_EQUAL_FLOAT(1.0f, mag1);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, mag2);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, mag3);
    TEST_ASSERT_EQUAL_FLOAT((float)sqrt(14.0f), mag4);
    TEST_ASSERT_EQUAL_FLOAT((float)sqrt(14.0f), mag5);
}

void test_norm(void){
    vect3 v = vector(4.0f, 0.0f, 0.0f);
    vect3 normalized = norm(&v);
    
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 1.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.0f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.0f, normalized.z);

    v = vector(1.0f ,2.0f ,3.0f);
    normalized = norm(&v);

    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.26726f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.53452f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(EPSILON, 0.80178f, normalized.z);
}

void test_dot(void){
    vect3 v1 = vector(1.0f, 2.0f, 3.0f);
    vect3 v2 = vector(2.0f, 3.0f, 4.0f);

    float d = dot_p(&v1, &v2);

   TEST_ASSERT_EQUAL_FLOAT(20.0f, d);
}

void test_cross(void){
    vect3 v1 = vector(1.0f, 2.0f, 3.0f);
    vect3 v2 = vector(2.0f, 3.0f, 4.0f);

    vect3 c1 = cross_p(&v1, &v2);
    vect3 c2 = cross_p(&v2, &v1);

    TEST_ASSERT_EQUAL_FLOAT(-1.0f, c1.x);
    TEST_ASSERT_EQUAL_FLOAT(2.0f, c1.y);
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, c1.z);

    TEST_ASSERT_EQUAL_FLOAT(1.0f, c2.x);
    TEST_ASSERT_EQUAL_FLOAT(-2.0f, c2.y);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, c2.z);
}

void test_color_create(void){
    color_t c1 = color_create(-0.5f, 0.4f, 1.7f);

    TEST_ASSERT_EQUAL_FLOAT(-0.5f, c1.r);
    TEST_ASSERT_EQUAL_FLOAT(0.4f, c1.g);
    TEST_ASSERT_EQUAL_FLOAT(1.7f, c1.b);
}

void test_color_add(void){
    color_t c1 = color_create(0.9f, 0.6f, 0.75f);
    color_t c2 = color_create(0.7f, 0.1f, 0.25f);
  
    color_t c4 = color_add(&c1, &c2);

    TEST_ASSERT_EQUAL_FLOAT(1.6f, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.7f, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, c4.b);
}

void test_color_sub(void){
    color_t c1 = color_create(0.9f, 0.6f, 0.75f);
    color_t c2 = color_create(0.7f, 0.1f, 0.25f);
  
    color_t c4 = color_sub(&c1, &c2);

    TEST_ASSERT_EQUAL_FLOAT(0.2f, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.5f, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.5f, c4.b);
}

void test_color__scalar_mult(void){
    color_t c = color_create(0.2f, 0.3f, 0.4f);
    float scalar = 2.0f;
  
    color_t c4 = color_scalar_mult(scalar, &c);

    TEST_ASSERT_EQUAL_FLOAT(0.4f, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.6f, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.8f, c4.b);
}

void test_color_mult(void){
    color_t c1 = color_create(1.0f, 0.2f, 0.4f);
    color_t c2 = color_create(0.9f, 1.0f, 0.1f);
  
    color_t c4 = color_mult(&c1, &c2);

    TEST_ASSERT_EQUAL_FLOAT(0.9f, c4.r);
    TEST_ASSERT_EQUAL_FLOAT(0.2f, c4.g);
    TEST_ASSERT_EQUAL_FLOAT(0.04f, c4.b);
}

void test_canvas_create(void){
    
    int width = 10;
    int height = 20;
    canvas_t canvas = canvas_create(width, height);

    color_t color[width*height];

    for(int i = 0; i < width*height; i++){
        color[i].r = 0.0f;
        color[i].g = 0.0f;
        color[i].b = 0.0f;
    }

    for(int i = 0; i < width*height; i++){
        TEST_ASSERT_EQUAL_FLOAT(color[i].r, canvas.pixel[i].r);
        TEST_ASSERT_EQUAL_FLOAT(color[i].g, canvas.pixel[i].g);
        TEST_ASSERT_EQUAL_FLOAT(color[i].b, canvas.pixel[i].b);
    }


    TEST_ASSERT_EQUAL(10, width);
    TEST_ASSERT_EQUAL(20, height);
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