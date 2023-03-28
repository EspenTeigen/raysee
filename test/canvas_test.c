#include <unity.h>
#include <tuples.h>
#include <canvas.h>
#include <stdlib.h>

#define CANVAS_WIDTH 10L
#define CANVAS_HEIGHT 20L

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}

void test_canvas_create(void){
    

    canvas_t* canvas = canvas_create(CANVAS_WIDTH, CANVAS_HEIGHT);

    color_t color[CANVAS_WIDTH*CANVAS_HEIGHT];

    for(int i = 0; i < CANVAS_WIDTH*CANVAS_HEIGHT; i++){
        color[i].r = 0.0f;
        color[i].g = 0.0f;
        color[i].b = 0.0f;
    }

    for(int i = 0; i < CANVAS_WIDTH*CANVAS_HEIGHT; i++){
        TEST_ASSERT_EQUAL_FLOAT(color[i].r, canvas->pixels[i].r);
        TEST_ASSERT_EQUAL_FLOAT(color[i].g, canvas->pixels[i].g);
        TEST_ASSERT_EQUAL_FLOAT(color[i].b, canvas->pixels[i].b);
    }


    TEST_ASSERT_EQUAL(10, canvas->width);
    TEST_ASSERT_EQUAL(20, canvas->height);

    canvas_delete(&canvas);
    TEST_ASSERT_NULL(canvas);
}

void test_canvas_write_pixel(void){
    canvas_t* canvas = canvas_create(CANVAS_WIDTH, CANVAS_HEIGHT);
    color_t red = color_create(1.0f, 0.0f, 0.0f);

    canvas_write_pixel(canvas, 2, 3, &red);

    TEST_ASSERT_EQUAL_FLOAT(red.r, canvas->pixels[2 + 3*CANVAS_WIDTH].r);
    TEST_ASSERT_EQUAL_FLOAT(red.g, canvas->pixels[2 + 3*CANVAS_WIDTH].g);
    TEST_ASSERT_EQUAL_FLOAT(red.b, canvas->pixels[2 + 3*CANVAS_WIDTH].b);
    canvas_delete(&canvas);
}

void test_canvas_create_ppm(void){

    canvas_t* canvas = canvas_create(5, 3);

    color_t color1 = color_create(1.0f, 0.9f, 0.8f);
    color_t color2 = color_create(0.1f, 0.2f, 0.3f);

    canvas_write_pixel(canvas, 0, 0, &color1);
    canvas_write_pixel(canvas, 4, 2, &color2);

    canvas_to_ppm(canvas, "../../faen.ppm");
    canvas_delete(&canvas);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_canvas_create);
    RUN_TEST(test_canvas_write_pixel);
    RUN_TEST(test_canvas_create_ppm);
    return UNITY_END();
}