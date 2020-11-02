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

void assert_farr_eq(float *a, float *b, int len, char *msg)
{
    while(--len && assert_float_eq(a[len], b[len], msg));
}

void assert_vec2_eq(vec2 v, vec2 exp, char *msg)
{
    assert_farr_eq(v.val, exp.val, 2, msg);
}

void assert_vec3_eq(vec3 v, vec3 exp, char *msg)
{
    assert_farr_eq(v.val, exp.val, 3, msg);
}

void assert_vec4_eq(vec4 v, vec4 exp, char *msg)
{
    assert_farr_eq(v.val, exp.val, 4, msg);
}

void assert_mat2_eq(mat2 m, mat2 exp, char *msg)
{
    assert_farr_eq(m.val, exp.val, 4, msg);
}

void assert_mat3_eq(mat3 m, mat3 exp, char *msg)
{
    assert_farr_eq(m.val, exp.val, 9, msg);
}

void assert_mat4_eq(mat4 m, mat4 exp, char *msg)
{
    assert_farr_eq(m.val, exp.val, 16, msg);
}
