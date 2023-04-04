#include <unity.h>
#include <stdlib.h>
#include <matrices.h>

void setUp(void) {
    
}


void tearDown(void) {
    // clean stuff up here
}


void test_inspection_2x(void){

    matrix2 m = {
        {-3.0, 5.0},
        {1.0, -2.0}
    };

    TEST_ASSERT_EQUAL_FLOAT(-3.0, m[0][0]);
    TEST_ASSERT_EQUAL_FLOAT(5.0, m[0][1]);
    TEST_ASSERT_EQUAL_FLOAT(1.0, m[1][0]);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, m[1][1]);
}

void test_inspection_3x(void){

    matrix3 m = {
        {-3.0, 5.0, 0.0},
        {1.0, -2.0, -7.0},
        {0.0, 1.0, 1.0}};
    
    TEST_ASSERT_EQUAL_FLOAT(-3.0, m[0][0]);
    TEST_ASSERT_EQUAL_FLOAT(-2.0, m[1][1]);
    TEST_ASSERT_EQUAL_FLOAT(1.0, m[2][2]);
}

void test_inspection_4x(void){

    matrix4 m = {
        {1.0, 2.0, 3.0, 4.0},
        {5.5, 6.5, 7.5, 8.5},
        {9.0, 10.0, 11.0, 12.0},
        {13.5, 14.5, 15.5, 16.7}};
    
    TEST_ASSERT_EQUAL_FLOAT(1.0, m[0][0]);
    TEST_ASSERT_EQUAL_FLOAT(4.0, m[0][3]);
    TEST_ASSERT_EQUAL_FLOAT(5.5, m[1][0]);
    TEST_ASSERT_EQUAL_FLOAT(7.5, m[1][2]);
    TEST_ASSERT_EQUAL_FLOAT(11.0, m[2][2]);
    TEST_ASSERT_EQUAL_FLOAT(13.5, m[3][0]);
    TEST_ASSERT_EQUAL_FLOAT(15.5, m[3][2]);
}

void test_matrix2_equal(void){
    matrix2 m1 = {
        {-3.0, 5.0},
        {1.0, -2.0}
    };
    matrix2 m2 = {
        {-3.0, 5.0},
        {1.0, -2.0}
    };

    bool equal = matrix2_equal(m1, m2);

    TEST_ASSERT_TRUE(equal);
}

void test_matrix4_mult(void){
    matrix4 mat1 = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 8.0, 7.0, 6.0},
        {5.0, 4.0, 3.0, 2.0}
    };
    matrix4 mat2 = {
        {-2.0, 1.0, 2.0, 3.0},
        {3.0, 2.0, 1.0, -1.0},
        {4.0, 3.0, 6.0, 5.0},
        {1.0, 2.0, 7.0, 8.0}
    };

    matrix4 res = {0};
    matrix4_mult(mat1, mat2, res);

    matrix4 control = {
        {20.0, 22.0, 50.0, 48.0},
        {44.0, 54.0, 114.0, 108.0},
        {40.0 , 58.0, 110.0 , 102.0},
        {16.0, 26.0, 46.0, 42.0}
    };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            TEST_ASSERT_EQUAL_FLOAT(control[i][j], res[i][j]);
        }
    }
}

void test_matrix4_vect3_mult(void){
    matrix4 m = {
        {1.0, 2.0, 3.0, 4.0},
        {2.0, 4.0, 4.0, 2.0},
        {8.0, 6.0, 4.0, 1.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    vect3 v = {
        1.0,
        2.0,
        3.0,
        1.0
    };

    vect3 res = {0};

    matrix4_vect3_mult(m, v, res);
    TEST_ASSERT_EQUAL_FLOAT(18.0, res[X]);
    TEST_ASSERT_EQUAL_FLOAT(24.0, res[Y]);
    TEST_ASSERT_EQUAL_FLOAT(33.0, res[Z]);
    TEST_ASSERT_EQUAL_FLOAT(1.0,  res[W]);
}

void test_identity_matrix(void){
    matrix4 mat = {
        {0.0, 1.0, 2.0,  4.0},
        {1.0, 2.0, 4.0,  8.0},
        {2.0, 4.0, 8.0,  16.0},
        {4.0, 8.0, 16.0, 32.0}
    };

    matrix4 I = {0};
    matrix4_get_identity(I);
    matrix4 res = {0};

    matrix4_mult(mat, I, res);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            TEST_ASSERT_EQUAL_FLOAT(mat[i][j], res[i][j]);
        }
    }
}

void test_matrix4_transpose(void){
    matrix4 a = {
        {0.0, 9.0, 3.0,  0.0},
        {9.0, 8.0, 0.0,  8.0},
        {1.0, 8.0, 5.0,  3.0},
        {0.0, 0.0, 5.0,  8.0}
    };
    
    matrix4 b = {
        {0.0, 9.0, 1.0,  0.0},
        {9.0, 8.0, 8.0,  0.0},
        {3.0, 0.0, 5.0,  5.0},
        {0.0, 8.0, 3.0,  8.0}
    };

    matrix4 res = {0};
    matrix4_transpose(a, res);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            TEST_ASSERT_EQUAL_FLOAT(b[i][j], res[i][j]);
        }
    }
}

void test_matrix2_det(void){
    matrix2 a ={
        {1.0, 5.0},
        {-3.0, 2.0}
    };

    double det = matrix2_det(a);
    TEST_ASSERT_EQUAL_FLOAT(17, det);
}


void test_matrix4_det(void){
    matrix4 a = {
        {-2.0, -8.0,   3.0,  5.0},
        {-3.0,  1.0,   7.0,  3.0},
        { 1.0,  2.0,  -9.0,  6.0},
        {-6.0,  7.0,   7.0, -9.0}
    };

    TEST_ASSERT_EQUAL_FLOAT(-4071.0, matrix4_det(a));

}

void test_matrix3_submatrix(void){
    matrix3 a = {
        { 1.0, 5.0,  0.0},
        {-3.0, 2.0,  7.0},
        { 0.0, 6.0, -3.0}
    };

    matrix2 res = {0};

    matrix3_submatrix(a, 0, 2, res);

    TEST_ASSERT_EQUAL_FLOAT(-3.0, res[0][0]);
    TEST_ASSERT_EQUAL_FLOAT( 2.0, res[0][1]);
    TEST_ASSERT_EQUAL_FLOAT( 0.0, res[1][0]);
    TEST_ASSERT_EQUAL_FLOAT( 6.0, res[1][1]);

}

void test_matrix4_submatrix(void){
    matrix4 a = {
        { -6.0, 1.0,  1.0, 6.0},
        { -8.0, 5.0,  8.0, 6.0},
        { -1.0, 0.0,  8.0, 2.0},
        { -7.0, 1.0, -1.0, 1.0}
    };

    matrix3 res = {0};

    matrix4_submatrix(a, 2, 1, res);

    TEST_ASSERT_EQUAL_FLOAT(-6.0, res[0][0]);
    TEST_ASSERT_EQUAL_FLOAT( 1.0, res[0][1]);
    TEST_ASSERT_EQUAL_FLOAT( 6.0, res[0][2]);

    TEST_ASSERT_EQUAL_FLOAT( -8.0, res[1][0]);
    TEST_ASSERT_EQUAL_FLOAT( 8.0, res[1][1]);
    TEST_ASSERT_EQUAL_FLOAT( 6.0, res[1][2]);

    TEST_ASSERT_EQUAL_FLOAT( -7.0, res[2][0]);
    TEST_ASSERT_EQUAL_FLOAT( -1.0, res[2][1]);
    TEST_ASSERT_EQUAL_FLOAT( 1.0, res[2][2]);
}

void test_matrix3_minor(void){
    matrix3 A = {
        {3.0,  5.0,  0.0},
        {2.0, -1.0, -7.0},
        {6.0, -1.0,  5.0}
    };

    matrix2 B = {0};

    matrix3_submatrix(A, 1, 0, B);
    double det1 = matrix2_det(B);
    TEST_ASSERT_EQUAL_FLOAT(25.0, det1);

    double det2 = matrix3_minor(A, 1, 0);
    TEST_ASSERT_EQUAL_FLOAT(25.0, det2);
}

void test_matrix3_cofactor(void){
    matrix3 A = {
        { 3.0,  5.0,  0.0},
        { 2.0, -1.0, -7.0},
        { 6.0, -1.0,  5.0}
    };

    double minor = matrix3_minor(A, 0, 0);
    TEST_ASSERT_EQUAL_FLOAT(-12.0, minor);
    double cofactor = matrix3_cofactor(A, 0 ,0);
    TEST_ASSERT_EQUAL_FLOAT(-12.0, cofactor);

    minor = matrix3_minor(A, 1, 0);
    TEST_ASSERT_EQUAL_FLOAT(25.0, minor);
    cofactor = matrix3_cofactor(A, 1 ,0);
    TEST_ASSERT_EQUAL_FLOAT(-25.0, cofactor);

}

void test_3x3_det(void){
    matrix3 A = {
        {  1.0,  2.0,  6.0},
        { -5.0,  8.0, -4.0},
        {  2.0,  6.0,  4.0}
    };

    double cofactor = matrix3_cofactor(A, 0, 0);
    TEST_ASSERT_EQUAL_FLOAT(56.0, cofactor);
    cofactor = matrix3_cofactor(A, 0, 1);
    TEST_ASSERT_EQUAL_FLOAT(12.0, cofactor);
    cofactor = matrix3_cofactor(A, 0, 2);
    TEST_ASSERT_EQUAL_FLOAT(-46.0, cofactor);

    double det = matrix3_det(A);
    TEST_ASSERT_EQUAL_FLOAT(-196.0, det);

}

void test_4x4_det(void){
    matrix4 A = {
        { -2.0, -8.0,  3.0,  5.0},
        { -3.0,  1.0,  7.0,  3.0},
        {  1.0,  2.0, -9.0,  6.0},
        { -6.0,  7.0,  7.0, -9.0}
    };

    double cofactor = matrix4_cofactor(A, 0, 0);
    TEST_ASSERT_EQUAL_FLOAT(690.0, cofactor);
    cofactor = matrix4_cofactor(A, 0, 1);
    TEST_ASSERT_EQUAL_FLOAT(447.0, cofactor);
    cofactor = matrix4_cofactor(A, 0, 2);
    TEST_ASSERT_EQUAL_FLOAT(210.0, cofactor);
    cofactor = matrix4_cofactor(A, 0, 3);
    TEST_ASSERT_EQUAL_FLOAT(51.0, cofactor);

    double det = matrix4_det(A);
    TEST_ASSERT_EQUAL_FLOAT(-4071.0, det);

}

//void test_matrix4_is_invertible(void){
//    matrix4 a = {
//        {6.0,  4.0, 4.0,  4.0},
//        {5.0,  5.0, 7.0,  6.0},
//        {4.0, -9.0, 3.0, -7.0},
//        {9.0,  1.0, 7.0, -6.0}
//    };
//
//    TEST_ASSERT_EQUAL(-2120.0, matrix4_det(a));
//}

//void test_matrix4_is_non_invertible(void){
//    matrix4 a = {
//        {-4.0,  2.0, -2.0, -3.0},
//        { 9.0,  6.0,  2.0,  6.0},
//        { 0.0, -5.0,  1.0, -5.0},
//        { 0.0,  0.0,  0.0,  0.0}
//    };
//
//    TEST_ASSERT_EQUAL(0.0, matrix4_det(a));
//}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_inspection_2x);
    RUN_TEST(test_inspection_3x);
    RUN_TEST(test_inspection_4x);
    RUN_TEST(test_matrix2_equal);
    RUN_TEST(test_matrix4_mult);
    RUN_TEST(test_matrix4_vect3_mult);
    RUN_TEST(test_identity_matrix);
    RUN_TEST(test_matrix4_transpose);
    RUN_TEST(test_matrix2_det);
    RUN_TEST(test_matrix3_submatrix);
    RUN_TEST(test_matrix4_submatrix);
    RUN_TEST(test_matrix3_minor);
    RUN_TEST(test_matrix3_cofactor);
    RUN_TEST(test_3x3_det);
    RUN_TEST(test_4x4_det);
   // RUN_TEST(test_matrix4_is_invertible);
    //RUN_TEST(test_matrix4_is_non_invertible);
    return UNITY_END();
}