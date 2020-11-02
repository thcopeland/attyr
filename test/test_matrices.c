#include "test_helpers.h"

void test_duplication_vec2(void)
{
    vec2 a = { .val = { 1, 2 } };
    vec2 b;

    dup_vec2(&a, &b);
    assert_vec2_eq(a, b, "vec2 duplication");
}

void test_duplication_vec3(void)
{
    vec3 a = { .val = { 1, 2, 3 } };
    vec3 b;

    dup_vec3(&a, &b);
    assert_vec3_eq(a, b, "vec3 duplication");
}

void test_duplication_vec4(void)
{
    vec4 a = { .val = { 1, 2, 3, 4 } };
    vec4 b;

    dup_vec4(&a, &b);
    assert_vec4_eq(a, b, "vec4 duplication");
}

void test_duplication_mat2(void)
{
    mat2 a = { .val = { 4,6,8,3 } };
    mat2 b;

    dup_mat2(&a, &b);
    assert_mat2_eq(a, b, "mat2 duplication");
}

void test_duplication_mat3(void)
{
    mat3 a = { .val = { 4,6,8,3,5,2,9,5,4 } };
    mat3 b;

    dup_mat3(&a, &b);
    assert_mat3_eq(a, b, "mat3 duplication");
}


void test_duplication_mat4(void)
{
    mat4 a = { .val = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 } };
    mat4 b;

    dup_mat4(&a, &b);
    assert_mat4_eq(a, b, "mat4 duplication");
}

void test_scaling_vec2(void)
{
    vec2 a = { .val = { 1, 2 } };
    vec2 exp = { .val = { 2, 4} };

    scale_vec2(&a, 2);
    assert_vec2_eq(a, exp, "vec2 scaling");
}

void test_scaling_vec3(void)
{
    vec3 a = { .val = { 1, 2, 3 } };
    vec3 exp = { .val = { 2, 4, 6 } };

    scale_vec3(&a, 2);
    assert_vec3_eq(a, exp, "vec3 scaling");
}

void test_scaling_vec4(void)
{
    vec4 a = { .val = { 1, 2, 3, 4 } };
    vec4 exp = { .val = { -2, -4, -6, -8 } };

    scale_vec4(&a, -2);
    assert_vec4_eq(a, exp, "vec4 scaling");
}

void test_scaling_mat2(void)
{
    mat2 a = { .val = { 4,6,8,3 } };
    mat2 exp = { .val = { 2,3,4,1.5 }};

    scale_mat2(&a, 0.5);
    assert_mat2_eq(a, exp, "mat2 scaling");
}

void test_scaling_mat3(void)
{
    mat3 a = { .val = { 4,6,8,3,5,2,9,5,4 } };
    mat3 exp = { .val = { 2,3,4,1.5,2.5,1,4.5,2.5,2 }};

    scale_mat3(&a, 0.5);
    assert_mat3_eq(a, exp, "mat3 scaling");
}

void test_scaling_mat4(void)
{
    mat4 a = { .val = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 } };
    mat4 exp = { .val = { 8,12,16,6,10,4,18,10,8,6,12,8,6,16,8,4} };

    scale_mat4(&a, 2);
    assert_mat4_eq(a, exp, "mat4 scaling");
}

void test_addition_vec2(void)
{
    vec2 a = { .val = { 1, 2 } };
    vec2 b = { .val = { 4, -1 } };
    vec2 exp = { .val = { 5, 1 } };

    add_vec2(&a, &b, &a);
    assert_vec2_eq(a, exp, "vec2 addition");
}

void test_addition_vec3(void)
{
    vec3 a = { .val = { 1, 2, 3 } };
    vec3 b = { .val = { 4, -1, 1 } };
    vec3 exp = { .val = { 5, 1, 4 } };

    add_vec3(&a, &b, &a);
    assert_vec3_eq(a, exp, "vec3 addition");
}

void test_addition_vec4(void)
{
    vec4 a = { .val = { 1, 2, 3, 4 } };
    vec4 b = { .val = { 4, -1, 1, 7 } };
    vec4 exp = { .val = { 5, 1, 4, 11 } };

    add_vec4(&a, &b, &a);
    assert_vec4_eq(a, exp, "vec4 addition");
}

void test_addition_mat2(void)
{
    mat2 a = { .val = { 4,6,8,3 } };
    mat2 b = { .val = { 8,3,2,8 } };
    mat2 exp = { .val = { 12,9,10,11 } };

    add_mat2(&a, &b, &a);
    assert_mat2_eq(a, exp, "mat2 addition");
}

void test_addition_mat3(void)
{
    mat3 a = { .val = { 4,6,8,3,5,2,9,5,4 } };
    mat3 b = { .val = { 8,3,2,8,2,8,4,6,3 } };
    mat3 exp = { .val = { 12,9,10,11,7,10,13,11,7 } };

    add_mat3(&a, &b, &a);
    assert_mat3_eq(a, exp, "mat3 addition");
}

void test_addition_mat4(void)
{
    mat4 a = { .val = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 } };
    mat4 b = { .val = { 8,3,2,8,2,8,4,6,3,4,8,4,2,1,3,9 } };
    mat4 exp = { .val = { 12,9,10,11,7,10,13,11,7,7,14,8,5,9,7,11 } };

    add_mat4(&a, &b, &a);
    assert_mat4_eq(a, exp, "mat4 addition");
}

void test_subtraction_vec2(void)
{
    vec2 a = { .val = { 1, 2 } };
    vec2 b = { .val = { 4, -1 } };
    vec2 exp = { .val = { -3, 3 } };

    sub_vec2(&a, &b, &a);
    assert_vec2_eq(a, exp, "vec2 subtraction");
}

void test_subtraction_vec3(void)
{
    vec3 a = { .val = { 1, 2, 3 } };
    vec3 b = { .val = { 4, -1, 1 } };
    vec3 exp = { .val = { -3, 3, 2 } };

    sub_vec3(&a, &b, &a);
    assert_vec3_eq(a, exp, "vec3 subtraction");
}

void test_subtraction_vec4(void)
{
    vec4 a = { .val = { 1, 2, 3, 4 } };
    vec4 b = { .val = { 4, -1, 1, 7 } };
    vec4 exp = { .val = { -3, 3, 2, -3 } };

    sub_vec4(&a, &b, &a);
    assert_vec4_eq(a, exp, "vec4 subtraction");
}

void test_subtraction_mat2(void)
{
    mat2 a = { .val = { 4,6,8,3 } };
    mat2 b = { .val = { 8,3,2,8 } };
    mat2 exp = { .val = { -4,3,6,-5 } };

    sub_mat2(&a, &b, &a);
    assert_mat2_eq(a, exp, "mat2 subtraction");
}

void test_subtraction_mat3(void)
{
    mat3 a = { .val = { 4,6,8,3,5,2,9,5,4 } };
    mat3 b = { .val = { 8,3,2,8,2,8,4,6,3 } };
    mat3 exp = { .val = { -4,3,6,-5,3,-6,5,-1,1 } };

    sub_mat3(&a, &b, &a);
    assert_mat3_eq(a, exp, "mat3 subtraction");
}

void test_subtraction_mat4(void)
{
    mat4 a = { .val = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 } };
    mat4 b = { .val = { 8,3,2,8,2,8,4,6,3,4,8,4,2,1,3,9 } };
    mat4 exp = { .val = { -4,3,6,-5,3,-6,5,-1,1,-1,-2,0,1,7,1,-7 } };

    sub_mat4(&a, &b, &a);
    assert_mat4_eq(a, exp, "mat4 subtraction");
}

void test_hadamard_vec2(void)
{
    vec2 a = { .val = { 1, 2 } };
    vec2 b = { .val = { 4, -1 } };
    vec2 exp = { .val = { 4, -2 } };

    had_vec2(&a, &b, &a);
    assert_vec2_eq(a, exp, "vec2 hadamard");
}

void test_hadamard_vec3(void)
{
    vec3 a = { .val = { 1, 2, 3 } };
    vec3 b = { .val = { 4, -1, 1 } };
    vec3 exp = { .val = { 4, -2, 3 } };

    had_vec3(&a, &b, &a);
    assert_vec3_eq(a, exp, "vec3 hadamard");
}

void test_hadamard_vec4(void)
{
    vec4 a = { .val = { 1, 2, 3, 4 } };
    vec4 b = { .val = { 4, -1, 1, 7 } };
    vec4 exp = { .val = { 4, -2, 3, 28 } };

    had_vec4(&a, &b, &a);
    assert_vec4_eq(a, exp, "vec4 hadamard");
}

void test_hadamard_mat2(void)
{
    mat2 a = { .val = { 4,6,8,3 } };
    mat2 b = { .val = { 8,3,2,8 } };
    mat2 exp = { .val = { 32,18,16,24 } };

    had_mat2(&a, &b, &a);
    assert_mat2_eq(a, exp, "mat2 hadamard");
}

void test_hadamard_mat3(void)
{
    mat3 a = { .val = { 4,6,8,3,5,2,9,5,4 } };
    mat3 b = { .val = { 8,3,2,8,2,8,4,6,3 } };
    mat3 exp = { .val = { 32,18,16,24,10,16,36,30,12 } };

    had_mat3(&a, &b, &a);
    assert_mat3_eq(a, exp, "mat3 hadamard");
}

void test_hadamard_mat4(void)
{
    mat4 a = { .val = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 } };
    mat4 b = { .val = { 8,3,2,8,2,8,4,6,3,4,8,4,2,1,3,9 } };
    mat4 exp = { .val = { 32,18,16,24,10,16,36,30,12,12,48,16,6,8,12,18  } };

    had_mat4(&a, &b, &a);
    assert_mat4_eq(a, exp, "mat4 hadamard");
}

void test_dot_product_vec2(void)
{
    vec2 a = { .val = { 1,2 } };
    vec2 b = { .val = { 2,4 } };

    assert_float_eq(dot_vec2(&a, &b), 10.0, "vec2 dot product");
}

void test_dot_product_vec3(void)
{
    vec3 a = { .val = { 1,2,3 } };
    vec3 b = { .val = { 2,4,8 } };

    assert_float_eq(dot_vec3(&a, &b), 34.0, "vec3 dot product");
}

void test_dot_product_vec4(void)
{
    vec4 a = { .val = { 1,2,3,2 } };
    vec4 b = { .val = { 2,4,8,16 } };

    assert_float_eq(dot_vec4(&a, &b), 66.0, "vec4 dot product");
}

void test_dot_product_mat2(void)
{
    mat2 a = { .val = { 3,6,2,9 } };
    mat2 b = { .val = { 1,1,3,5 } };
    mat2 c;
    mat2 exp = { .val = { 21,33,29,47 } };

    dot_mat2(&a, &b, &c);
    assert_mat2_eq(c, exp, "mat2 dot product");
}

void test_dot_product_mat3(void)
{
    mat3 a = { .val = { 1,2,3,4,5,6,7,8,9 } };
    mat3 b = { .val = { 0,1,2,3,4,5,6,7,8 } };
    mat3 c;
    mat3 exp = { .val = { 24,30,36,51,66,81,78,102,126 } };

    dot_mat3(&a, &b, &c);
    assert_mat3_eq(c, exp, "mat3 dot product");
}

void test_dot_product_mat4(void)
{
    mat4 a = { .val = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 } };
    mat4 b = { .val = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 } };
    mat4 c;
    mat4 exp = { .val = { 80,90,100,110,176,202,228,254,272,314,356,398,368,426,484,542 } };

    dot_mat4(&a, &b, &c);
    assert_mat4_eq(c, exp, "mat4 dot product");
}

void test_dot_product_mat2vec2(void)
{
    mat2 a = { .val = { 1,2,3,4 } };
    vec2 b = { .val = { 10,1 } };
    vec2 c;
    vec2 exp = { .val = { 12, 34 } };

    dot_mat2vec2(&a, &b, &c);
    assert_vec2_eq(c, exp, "mat2 * vec2 dot product");
}

void test_dot_product_mat3vec3(void)
{
    mat3 a = { .val = { 1,2,3,4,5,6,7,8,9 } };
    vec3 b = { .val = { 10,1,-3 } };
    vec3 c;
    vec3 exp = { .val = { 3, 27, 51 } };

    dot_mat3vec3(&a, &b, &c);
    assert_vec3_eq(c, exp, "mat3 * vec3 dot product");
}

void test_dot_product_mat4vec4(void)
{
    mat4 a = { .val = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 } };
    vec4 b = { .val = { 10,1,-3,4 } };
    vec4 c;
    vec4 exp = { .val = { 19,67,115,163 } };

    dot_mat4vec4(&a, &b, &c);
    assert_vec4_eq(c, exp, "mat4 * vec4 dot product");
}

void test_matrices(void) {
    test_duplication_vec2();
    test_duplication_vec3();
    test_duplication_vec4();
    test_duplication_mat2();
    test_duplication_mat3();
    test_duplication_mat4();

    test_scaling_vec2();
    test_scaling_vec3();
    test_scaling_vec4();
    test_scaling_mat2();
    test_scaling_mat3();
    test_scaling_mat4();

    test_addition_vec2();
    test_addition_vec3();
    test_addition_vec4();
    test_addition_mat2();
    test_addition_mat3();
    test_addition_mat4();

    test_subtraction_vec2();
    test_subtraction_vec3();
    test_subtraction_vec4();
    test_subtraction_mat2();
    test_subtraction_mat3();
    test_subtraction_mat4();

    test_hadamard_vec2();
    test_hadamard_vec3();
    test_hadamard_vec4();
    test_hadamard_mat2();
    test_hadamard_mat3();
    test_hadamard_mat4();

    test_dot_product_vec2();
    test_dot_product_vec3();
    test_dot_product_vec4();

    test_dot_product_mat2();
    test_dot_product_mat3();
    test_dot_product_mat4();

    test_dot_product_mat2vec2();
    test_dot_product_mat3vec3();
    test_dot_product_mat4vec4();
}
