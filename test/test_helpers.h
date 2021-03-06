#ifndef HELPERS_H
#define HELPERS_H

#include "matrices.h"

void assert_float_eq(float actual, float exp, char *msg);
void assert_vec3_eq(attyr_vec3 v, attyr_vec3 exp, char *msg);
void assert_vec4_eq(attyr_vec4 v, attyr_vec4 exp, char *msg);
void assert_mat3x3_eq(attyr_mat3x3 m, attyr_mat3x3 exp, char *msg);
void assert_mat4x4_eq(attyr_mat4x4 m, attyr_mat4x4 exp, char *msg);

#endif
