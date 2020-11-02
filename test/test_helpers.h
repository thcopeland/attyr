#ifndef HELPERS_H
#define HELPERS_H

#include "matrices.h"

int assert_float_eq(float a, float b, char *msg);
void assert_farr_eq(float *a, float *b, int len, char *msg);
void assert_vec2_eq(vec2 v, vec2 exp, char *msg);
void assert_vec3_eq(vec3 v, vec3 exp, char *msg);
void assert_vec4_eq(vec4 v, vec4 exp, char *msg);
void assert_mat2_eq(mat2 v, mat2 exp, char *msg);
void assert_mat3_eq(mat3 m, mat3 exp, char *msg);
void assert_mat4_eq(mat4 m, mat4 exp, char *msg);

#endif
