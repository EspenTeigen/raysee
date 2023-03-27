#include <unity.h>
#include <tuples.h>
#include <canvas.h>

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}

void test_canvas_create(void){
    #define CANVAS_WIDTH 10
    #define CANVAS_HEIGHT 20


    canvas_t canvas = canvas_create(CANVAS_HEIGHT, CANVAS_WIDTH);
    printf("%f\n", canvas.pixel->b[0]);
    color_t color[CANVAS_WIDTH*CANVAS_HEIGHT];

    for(int i = 0; i < CANVAS_WIDTH*CANVAS_HEIGHT; i++){
        color[i].r = 0.0f;
        color[i].g = 0.0f;
        color[i].b = 0.0f;
    }

    for(int i = 0; i < CANVAS_WIDTH*CANVAS_HEIGHT; i++){
        TEST_ASSERT_EQUAL_FLOAT(color[i].r, canvas.pixel[i].r);
        TEST_ASSERT_EQUAL_FLOAT(color[i].g, canvas.pixel[i].g);
        TEST_ASSERT_EQUAL_FLOAT(color[i].b, canvas.pixel[i].b);
    }


    TEST_ASSERT_EQUAL(10, CANVAS_WIDTH);
    TEST_ASSERT_EQUAL(20, CANVAS_HEIGHT);
    
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_canvas_create);
    return UNITY_END();
}