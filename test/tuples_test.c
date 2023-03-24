#include <unity.h>
#include <tuples.h>

#define EPSILON 0.00001
void setUp(void) {
    
}

void tearDown(void) {
    // clean stuff up here
}


void test_tuple_is_point(void) {
    vect3 v1 = {
        .x = 4.3,
        .y = -4.2,
        .z = 3.1,
        .w = 1.0
    };

    vect3 v2 = tuple(4.3, -4.2, 3.1, 1.0);
    
    TEST_ASSERT_EQUAL_FLOAT(v1.x, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(v1.y, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(v1.z, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(v1.w, v2.w);
}

void test_tuple_is_vector(void) {
    vect3 v1 = {
        .x = 4.3,
        .y = -4.2,
        .z = 3.1,
        .w = 0.0
    };

    vect3 v2 = tuple(4.3, -4.2, 3.1, 0.0);

    TEST_ASSERT_EQUAL_FLOAT(v1.x, v2.x);
    TEST_ASSERT_EQUAL_FLOAT(v1.y, v2.y);
    TEST_ASSERT_EQUAL_FLOAT(v1.z, v2.z);
    TEST_ASSERT_EQUAL_FLOAT(v1.w, v2.w);
}

void test_point(void){
    vect3 p1 = {
        .x = 4.0,
        .y = -4.0,
        .z = 3.0,
        .w = 1.0
    };

    vect3 p2 = point(4.0, -4.0, 3);

    TEST_ASSERT_EQUAL_FLOAT(p1.x, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(p1.y, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(p1.z, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(p1.w, p2.w);
}

void test_vector(void){
    vect3 p1 = {
        .x = 4.0,
        .y = -4.0,
        .z = 3.0,
        .w = 0.0
    };

    vect3 p2 = vector(4.0, -4.0, 3);

    TEST_ASSERT_EQUAL_FLOAT(p1.x, p2.x);
    TEST_ASSERT_EQUAL_FLOAT(p1.y, p2.y);
    TEST_ASSERT_EQUAL_FLOAT(p1.z, p2.z);
    TEST_ASSERT_EQUAL_FLOAT(p1.w, p2.w);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_tuple_is_point);
    RUN_TEST(test_tuple_is_vector);
    RUN_TEST(test_point);
    RUN_TEST(test_vector);
    return UNITY_END();
}