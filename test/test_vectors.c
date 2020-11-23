#include "test_helpers.h"

void test_duplication_vec3(void)
{
    attyr_vec3 a = { 1, 2, 3 };
    attyr_vec3 b;

    attyr_dup_vec3(&a, &b);
    assert_vec3_eq(a, b, "vec3 duplication");
}

void test_duplication_vec4(void)
{
    attyr_vec4 a = { 1, 2, 3, 4 };
    attyr_vec4 b;

    attyr_dup_vec4(&a, &b);
    assert_vec4_eq(a, b, "vec4 duplication");
}


void test_scaling_vec3(void)
{
    attyr_vec3 a = { 1, 2, 3 };
    attyr_vec3 exp = { 2, 4, 6 };

    attyr_scale_vec3(&a, 2);
    assert_vec3_eq(a, exp, "vec3 scaling");
}

void test_scaling_vec4(void)
{
    attyr_vec4 a = { 1, 2, 3, 4 };
    attyr_vec4 exp = { -2, -4, -6, -8 };

    attyr_scale_vec4(&a, -2);
    assert_vec4_eq(a, exp, "vec4 scaling");
}

void test_addition_vec3(void)
{
    attyr_vec3 a = { 1, 2, 3 };
    attyr_vec3 b = { 4, -1, 1 };
    attyr_vec3 exp = { 5, 1, 4 };

    attyr_add_vec3(&a, &b, &a);
    assert_vec3_eq(a, exp, "vec3 addition");
}

void test_addition_vec4(void)
{
    attyr_vec4 a = { 1, 2, 3, 4 };
    attyr_vec4 b = { 4, -1, 1, 7 };
    attyr_vec4 exp = { 5, 1, 4, 11 };

    attyr_add_vec4(&a, &b, &a);
    assert_vec4_eq(a, exp, "vec4 addition");
}

void test_subtraction_vec3(void)
{
    attyr_vec3 a = { 1, 2, 3 };
    attyr_vec3 b = { 4, -1, 1 };
    attyr_vec3 exp = { -3, 3, 2 };

    attyr_sub_vec3(&a, &b, &a);
    assert_vec3_eq(a, exp, "vec3 subtraction");
}

void test_subtraction_vec4(void)
{
    attyr_vec4 a = { 1, 2, 3, 4 };
    attyr_vec4 b = { 4, -1, 1, 7 };
    attyr_vec4 exp = { -3, 3, 2, -3 };

    attyr_sub_vec4(&a, &b, &a);
    assert_vec4_eq(a, exp, "vec4 subtraction");
}

void test_hadamard_vec3(void)
{
    attyr_vec3 a = { 1, 2, 3 };
    attyr_vec3 b = { 4, -1, 1 };
    attyr_vec3 exp = { 4, -2, 3 };

    attyr_had_vec3(&a, &b, &a);
    assert_vec3_eq(a, exp, "vec3 hadamard");
}

void test_hadamard_vec4(void)
{
    attyr_vec4 a = { 1, 2, 3, 4 };
    attyr_vec4 b = { 4, -1, 1, 7 };
    attyr_vec4 exp = { 4, -2, 3, 28 };

    attyr_had_vec4(&a, &b, &a);
    assert_vec4_eq(a, exp, "vec4 hadamard");
}

void test_dot_product_vec3(void)
{
    attyr_vec3 a = { 1,2,3 };
    attyr_vec3 b = { 2,4,8 };

    assert_float_eq(attyr_dot_vec3(&a, &b), 34.0, "vec3 dot product");
}

void test_dot_product_vec4(void)
{
    attyr_vec4 a = { 1,2,3,2 };
    attyr_vec4 b = { 2,4,8,16 };

    assert_float_eq(attyr_dot_vec4(&a, &b), 66.0, "vec4 dot product");
}

int main(int argc, char **argv)
{
    test_duplication_vec3();
    test_duplication_vec4();

    test_scaling_vec3();
    test_scaling_vec4();

    test_addition_vec3();
    test_addition_vec4();

    test_subtraction_vec3();
    test_subtraction_vec4();

    test_hadamard_vec3();
    test_hadamard_vec4();

    test_dot_product_vec3();
    test_dot_product_vec4();

    return 0;
}
