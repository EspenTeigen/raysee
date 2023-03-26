#include <unity.h>
#include <tuples.h>
#include <canvas.h>

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
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
    RUN_TEST(test_canvas_create);
    return UNITY_END();
}