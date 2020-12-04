#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test_helpers.h"

void assert_float_eq(float actual, float expected, char *msg)
{
    if (fabs(actual-expected) > 0.0001) {
        printf("assert_float_eq: expected %f, received %f (%s)\n", expected, actual, msg);
        exit(-1);
    }
}

void assert_vec3_eq(attyr_vec3 v, attyr_vec3 exp, char *msg)
{
    assert_float_eq(v.x, exp.x, msg);
    assert_float_eq(v.y, exp.y, msg);
    assert_float_eq(v.z, exp.z, msg);
}

void assert_vec4_eq(attyr_vec4 v, attyr_vec4 exp, char *msg)
{
    assert_float_eq(v.x, exp.x, msg);
    assert_float_eq(v.y, exp.y, msg);
    assert_float_eq(v.z, exp.z, msg);
    assert_float_eq(v.w, exp.w, msg);
}

void assert_mat3x3_eq(attyr_mat3x3 m, attyr_mat3x3 exp, char *msg)
{
    assert_float_eq(m.m11, exp.m11, msg);
    assert_float_eq(m.m12, exp.m12, msg);
    assert_float_eq(m.m13, exp.m13, msg);
    assert_float_eq(m.m21, exp.m21, msg);
    assert_float_eq(m.m22, exp.m22, msg);
    assert_float_eq(m.m23, exp.m23, msg);
    assert_float_eq(m.m31, exp.m31, msg);
    assert_float_eq(m.m32, exp.m32, msg);
    assert_float_eq(m.m33, exp.m33, msg);
}

void assert_mat4x4_eq(attyr_mat4x4 m, attyr_mat4x4 exp, char *msg)
{
    assert_float_eq(m.m11, exp.m11, msg);
    assert_float_eq(m.m12, exp.m12, msg);
    assert_float_eq(m.m13, exp.m13, msg);
    assert_float_eq(m.m14, exp.m14, msg);
    assert_float_eq(m.m21, exp.m21, msg);
    assert_float_eq(m.m22, exp.m22, msg);
    assert_float_eq(m.m23, exp.m23, msg);
    assert_float_eq(m.m24, exp.m24, msg);
    assert_float_eq(m.m31, exp.m31, msg);
    assert_float_eq(m.m32, exp.m32, msg);
    assert_float_eq(m.m33, exp.m33, msg);
    assert_float_eq(m.m34, exp.m34, msg);
    assert_float_eq(m.m41, exp.m41, msg);
    assert_float_eq(m.m42, exp.m42, msg);
    assert_float_eq(m.m43, exp.m43, msg);
    assert_float_eq(m.m44, exp.m44, msg);
}
