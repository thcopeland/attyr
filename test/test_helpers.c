#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test_helpers.h"

int assert_float_eq(float a, float b, char *msg)
{
    if (fabs(a-b) > 0.01) {
        fprintf(stderr, "FAIL: %s\n", msg);
        return 0;
    }

    return 1;
}

void assert_vec3_eq(vec3 v, vec3 exp, char *msg)
{
    assert_float_eq(v.x, exp.x, msg) &&
    assert_float_eq(v.y, exp.y, msg) &&
    assert_float_eq(v.z, exp.z, msg);
}

void assert_vec4_eq(vec4 v, vec4 exp, char *msg)
{
    assert_float_eq(v.x, exp.x, msg) &&
    assert_float_eq(v.y, exp.y, msg) &&
    assert_float_eq(v.z, exp.z, msg) &&
    assert_float_eq(v.w, exp.w, msg);
}

void assert_mat3_eq(mat3 m, mat3 exp, char *msg)
{
    assert_float_eq(m.m11, exp.m11, msg) &&
    assert_float_eq(m.m12, exp.m12, msg) &&
    assert_float_eq(m.m13, exp.m13, msg) &&
    assert_float_eq(m.m21, exp.m21, msg) &&
    assert_float_eq(m.m22, exp.m22, msg) &&
    assert_float_eq(m.m23, exp.m23, msg) &&
    assert_float_eq(m.m31, exp.m31, msg) &&
    assert_float_eq(m.m32, exp.m32, msg) &&
    assert_float_eq(m.m33, exp.m33, msg);
}

void assert_mat4_eq(mat4 m, mat4 exp, char *msg)
{
    assert_float_eq(m.m11, exp.m11, msg) &&
    assert_float_eq(m.m12, exp.m12, msg) &&
    assert_float_eq(m.m13, exp.m13, msg) &&
    assert_float_eq(m.m14, exp.m14, msg) &&
    assert_float_eq(m.m21, exp.m21, msg) &&
    assert_float_eq(m.m22, exp.m22, msg) &&
    assert_float_eq(m.m23, exp.m23, msg) &&
    assert_float_eq(m.m24, exp.m24, msg) &&
    assert_float_eq(m.m31, exp.m31, msg) &&
    assert_float_eq(m.m32, exp.m32, msg) &&
    assert_float_eq(m.m33, exp.m33, msg) &&
    assert_float_eq(m.m34, exp.m34, msg) &&
    assert_float_eq(m.m41, exp.m41, msg) &&
    assert_float_eq(m.m42, exp.m42, msg) &&
    assert_float_eq(m.m43, exp.m43, msg) &&
    assert_float_eq(m.m44, exp.m44, msg);
}
