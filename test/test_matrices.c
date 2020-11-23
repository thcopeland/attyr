#include "test_helpers.h"

void test_duplication_mat3(void)
{
    attyr_mat3 a = { 4,6,8,3,5,2,9,5,4 };
    attyr_mat3 b;

    attyr_dup_mat3(&a, &b);
    assert_mat3_eq(a, b, "mat3 duplication");
}

void test_duplication_mat4(void)
{
    attyr_mat4 a = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 };
    attyr_mat4 b;

    attyr_dup_mat4(&a, &b);
    assert_mat4_eq(a, b, "mat4 duplication");
}

void test_scaling_mat3(void)
{
    attyr_mat3 a = { 4,6,8,3,5,2,9,5,4 };
    attyr_mat3 exp = { 2,3,4,1.5,2.5,1,4.5,2.5,2 };

    attyr_scale_mat3(&a, 0.5);
    assert_mat3_eq(a, exp, "mat3 scaling");
}

void test_scaling_mat4(void)
{
    attyr_mat4 a = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 };
    attyr_mat4 exp = { 8,12,16,6,10,4,18,10,8,6,12,8,6,16,8,4};

    attyr_scale_mat4(&a, 2);
    assert_mat4_eq(a, exp, "mat4 scaling");
}

void test_addition_mat3(void)
{
    attyr_mat3 a = { 4,6,8,3,5,2,9,5,4 };
    attyr_mat3 b = { 8,3,2,8,2,8,4,6,3 };
    attyr_mat3 exp = { 12,9,10,11,7,10,13,11,7 };

    attyr_add_mat3(&a, &b, &a);
    assert_mat3_eq(a, exp, "mat3 addition");
}

void test_addition_mat4(void)
{
    attyr_mat4 a = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 };
    attyr_mat4 b = { 8,3,2,8,2,8,4,6,3,4,8,4,2,1,3,9 };
    attyr_mat4 exp = { 12,9,10,11,7,10,13,11,7,7,14,8,5,9,7,11 };

    attyr_add_mat4(&a, &b, &a);
    assert_mat4_eq(a, exp, "mat4 addition");
}

void test_subtraction_mat3(void)
{
    attyr_mat3 a = { 4,6,8,3,5,2,9,5,4 };
    attyr_mat3 b = { 8,3,2,8,2,8,4,6,3 };
    attyr_mat3 exp = { -4,3,6,-5,3,-6,5,-1,1 };

    attyr_sub_mat3(&a, &b, &a);
    assert_mat3_eq(a, exp, "mat3 subtraction");
}

void test_subtraction_mat4(void)
{
    attyr_mat4 a = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 };
    attyr_mat4 b = { 8,3,2,8,2,8,4,6,3,4,8,4,2,1,3,9 };
    attyr_mat4 exp = { -4,3,6,-5,3,-6,5,-1,1,-1,-2,0,1,7,1,-7 };

    attyr_sub_mat4(&a, &b, &a);
    assert_mat4_eq(a, exp, "mat4 subtraction");
}


void test_hadamard_mat3(void)
{
    attyr_mat3 a = { 4,6,8,3,5,2,9,5,4 };
    attyr_mat3 b = { 8,3,2,8,2,8,4,6,3 };
    attyr_mat3 exp = { 32,18,16,24,10,16,36,30,12 };

    attyr_had_mat3(&a, &b, &a);
    assert_mat3_eq(a, exp, "mat3 hadamard");
}

void test_hadamard_mat4(void)
{
    attyr_mat4 a = { 4,6,8,3,5,2,9,5,4,3,6,4,3,8,4,2 };
    attyr_mat4 b = { 8,3,2,8,2,8,4,6,3,4,8,4,2,1,3,9 };
    attyr_mat4 exp = { 32,18,16,24,10,16,36,30,12,12,48,16,6,8,12,18  };

    attyr_had_mat4(&a, &b, &a);
    assert_mat4_eq(a, exp, "mat4 hadamard");
}

void test_dot_product_mat3(void)
{
    attyr_mat3 a = { 1,2,3,4,5,6,7,8,9 };
    attyr_mat3 b = { 0,1,2,3,4,5,6,7,8 };
    attyr_mat3 c;
    attyr_mat3 exp = { 24,30,36,51,66,81,78,102,126 };

    attyr_dot_mat3(&a, &b, &c);
    assert_mat3_eq(c, exp, "mat3 dot product");
}

void test_dot_product_mat4(void)
{
    attyr_mat4 a = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    attyr_mat4 b = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    attyr_mat4 c;
    attyr_mat4 exp = { 80,90,100,110,176,202,228,254,272,314,356,398,368,426,484,542 };

    attyr_dot_mat4(&a, &b, &c);
    assert_mat4_eq(c, exp, "mat4 dot product");
}

void test_invert_mat3(void)
{
    attyr_mat3 a = { 5,6,7,1,2,3,8,9,0 },
         v = a,
         d,
         s = { 0,0,0,0,0,0,0,0,0 },
         i = { 1,0,0,0,1,0,0,0,1 };

    assert_float_eq(attyr_invert_mat3(&v), -40, "mat3 inverse determinant");
    attyr_dot_mat3(&a, &v, &d);
    assert_mat3_eq(d, i, "mat3 inverse check");
    assert_float_eq(attyr_invert_mat3(&s), 0, "mat3 inverse determinant");
}


void test_dot_product_mat3vec3(void)
{
    attyr_mat3 a = { 1,2,3,4,5,6,7,8,9 };
    attyr_vec3 b = { 10,1,-3 };
    attyr_vec3 c;
    attyr_vec3 exp = { 3, 27, 51 };

    attyr_dot_mat3vec3(&a, &b, &c);
    assert_vec3_eq(c, exp, "mat3 * attyr_vec3 dot product");
}

void test_dot_product_mat4vec4(void)
{
    attyr_mat4 a = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    attyr_vec4 b = { 10,1,-3,4 };
    attyr_vec4 c;
    attyr_vec4 exp = { 19,67,115,163 };

    attyr_dot_mat4vec4(&a, &b, &c);
    assert_vec4_eq(c, exp, "mat4 * attyr_vec4 dot product");
}

int main(int argc, char **argv)
{
    test_duplication_mat3();
    test_duplication_mat4();

    test_scaling_mat3();
    test_scaling_mat4();

    test_addition_mat3();
    test_addition_mat4();

    test_subtraction_mat3();
    test_subtraction_mat4();

    test_hadamard_mat3();
    test_hadamard_mat4();

    test_dot_product_mat3();
    test_dot_product_mat4();

    test_dot_product_mat3vec3();
    test_dot_product_mat4vec4();

    test_invert_mat3();

    return 0;
}
