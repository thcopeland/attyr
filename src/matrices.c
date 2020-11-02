#include <string.h>
#include "matrices.h"

void dup_vec2(vec2 *src, vec2 *dst)
{
    memcpy(dst->val, src->val, sizeof(float)*2);
}

void dup_vec3(vec3 *src, vec3 *dst)
{
    memcpy(dst->val, src->val, sizeof(float)*3);
}

void dup_vec4(vec4 *src, vec4 *dst)
{
    memcpy(dst->val, src->val, sizeof(float)*4);
}

void dup_mat2(mat2 *src, mat2 *dst)
{
    memcpy(dst->val, src->val, sizeof(float)*4);
}

void dup_mat3(mat3 *src, mat3 *dst)
{
    memcpy(dst->val, src->val, sizeof(float)*9);
}

void dup_mat4(mat4 *src, mat4 *dst)
{
    memcpy(dst->val, src->val, sizeof(float)*16);
}

void scale_vec2(vec2 *v, float s)
{
    v->val[0] *= s;
    v->val[1] *= s;
}

void scale_vec3(vec3 *v, float s)
{
    v->val[0] *= s;
    v->val[1] *= s;
    v->val[2] *= s;
}

void scale_vec4(vec4 *v, float s)
{
    v->val[0] *= s;
    v->val[1] *= s;
    v->val[2] *= s;
    v->val[3] *= s;
}

void scale_mat2(mat2 *m, float s)
{
    m->val[0] *= s;
    m->val[1] *= s;
    m->val[2] *= s;
    m->val[3] *= s;
}

void scale_mat3(mat3 *m, float s)
{
    m->val[0] *= s;
    m->val[1] *= s;
    m->val[2] *= s;
    m->val[3] *= s;
    m->val[4] *= s;
    m->val[5] *= s;
    m->val[6] *= s;
    m->val[7] *= s;
    m->val[8] *= s;
}

void scale_mat4(mat4 *m, float s)
{
    m->val[0] *= s;
    m->val[1] *= s;
    m->val[2] *= s;
    m->val[3] *= s;
    m->val[4] *= s;
    m->val[5] *= s;
    m->val[6] *= s;
    m->val[7] *= s;
    m->val[8] *= s;
    m->val[9] *= s;
    m->val[10] *= s;
    m->val[11] *= s;
    m->val[12] *= s;
    m->val[13] *= s;
    m->val[14] *= s;
    m->val[15] *= s;
}

void add_vec2(vec2 *a, vec2 *b, vec2 *c)
{
    c->val[0] = a->val[0] + b->val[0];
    c->val[1] = a->val[1] + b->val[1];
}

void add_vec3(vec3 *a, vec3 *b, vec3 *c)
{
    c->val[0] = a->val[0] + b->val[0];
    c->val[1] = a->val[1] + b->val[1];
    c->val[2] = a->val[2] + b->val[2];
}

void add_vec4(vec4 *a, vec4 *b, vec4 *c)
{
    c->val[0] = a->val[0] + b->val[0];
    c->val[1] = a->val[1] + b->val[1];
    c->val[2] = a->val[2] + b->val[2];
    c->val[3] = a->val[3] + b->val[3];
}

void add_mat2(mat2 *a, mat2 *b, mat2 *c)
{
    c->val[0] = a->val[0] + b->val[0];
    c->val[1] = a->val[1] + b->val[1];
    c->val[2] = a->val[2] + b->val[2];
    c->val[3] = a->val[3] + b->val[3];
}

void add_mat3(mat3 *a, mat3 *b, mat3 *c)
{
    c->val[0] = a->val[0] + b->val[0];
    c->val[1] = a->val[1] + b->val[1];
    c->val[2] = a->val[2] + b->val[2];
    c->val[3] = a->val[3] + b->val[3];
    c->val[4] = a->val[4] + b->val[4];
    c->val[5] = a->val[5] + b->val[5];
    c->val[6] = a->val[6] + b->val[6];
    c->val[7] = a->val[7] + b->val[7];
    c->val[8] = a->val[8] + b->val[8];
}

void add_mat4(mat4 *a, mat4 *b, mat4 *c)
{
    c->val[0] = a->val[0] + b->val[0];
    c->val[1] = a->val[1] + b->val[1];
    c->val[2] = a->val[2] + b->val[2];
    c->val[3] = a->val[3] + b->val[3];
    c->val[4] = a->val[4] + b->val[4];
    c->val[5] = a->val[5] + b->val[5];
    c->val[6] = a->val[6] + b->val[6];
    c->val[7] = a->val[7] + b->val[7];
    c->val[8] = a->val[8] + b->val[8];
    c->val[9] = a->val[9] + b->val[9];
    c->val[10] = a->val[10] + b->val[10];
    c->val[11] = a->val[11] + b->val[11];
    c->val[12] = a->val[12] + b->val[12];
    c->val[13] = a->val[13] + b->val[13];
    c->val[14] = a->val[14] + b->val[14];
    c->val[15] = a->val[15] + b->val[15];
}

void sub_vec2(vec2 *a, vec2 *b, vec2 *c)
{
    c->val[0] = a->val[0] - b->val[0];
    c->val[1] = a->val[1] - b->val[1];
}

void sub_vec3(vec3 *a, vec3 *b, vec3 *c)
{
    c->val[0] = a->val[0] - b->val[0];
    c->val[1] = a->val[1] - b->val[1];
    c->val[2] = a->val[2] - b->val[2];
}

void sub_vec4(vec4 *a, vec4 *b, vec4 *c)
{
    c->val[0] = a->val[0] - b->val[0];
    c->val[1] = a->val[1] - b->val[1];
    c->val[2] = a->val[2] - b->val[2];
    c->val[3] = a->val[3] - b->val[3];
}

void sub_mat2(mat2 *a, mat2 *b, mat2 *c)
{
    c->val[0] = a->val[0] - b->val[0];
    c->val[1] = a->val[1] - b->val[1];
    c->val[2] = a->val[2] - b->val[2];
    c->val[3] = a->val[3] - b->val[3];
}

void sub_mat3(mat3 *a, mat3 *b, mat3 *c)
{
    c->val[0] = a->val[0] - b->val[0];
    c->val[1] = a->val[1] - b->val[1];
    c->val[2] = a->val[2] - b->val[2];
    c->val[3] = a->val[3] - b->val[3];
    c->val[4] = a->val[4] - b->val[4];
    c->val[5] = a->val[5] - b->val[5];
    c->val[6] = a->val[6] - b->val[6];
    c->val[7] = a->val[7] - b->val[7];
    c->val[8] = a->val[8] - b->val[8];
}

void sub_mat4(mat4 *a, mat4 *b, mat4 *c)
{
    c->val[0] = a->val[0] - b->val[0];
    c->val[1] = a->val[1] - b->val[1];
    c->val[2] = a->val[2] - b->val[2];
    c->val[3] = a->val[3] - b->val[3];
    c->val[4] = a->val[4] - b->val[4];
    c->val[5] = a->val[5] - b->val[5];
    c->val[6] = a->val[6] - b->val[6];
    c->val[7] = a->val[7] - b->val[7];
    c->val[8] = a->val[8] - b->val[8];
    c->val[9] = a->val[9] - b->val[9];
    c->val[10] = a->val[10] - b->val[10];
    c->val[11] = a->val[11] - b->val[11];
    c->val[12] = a->val[12] - b->val[12];
    c->val[13] = a->val[13] - b->val[13];
    c->val[14] = a->val[14] - b->val[14];
    c->val[15] = a->val[15] - b->val[15];
}

void had_vec2(vec2 *a, vec2 *b, vec2 *c)
{
    c->val[0] = a->val[0] * b->val[0];
    c->val[1] = a->val[1] * b->val[1];
}

void had_vec3(vec3 *a, vec3 *b, vec3 *c)
{
    c->val[0] = a->val[0] * b->val[0];
    c->val[1] = a->val[1] * b->val[1];
    c->val[2] = a->val[2] * b->val[2];
}

void had_vec4(vec4 *a, vec4 *b, vec4 *c)
{
    c->val[0] = a->val[0] * b->val[0];
    c->val[1] = a->val[1] * b->val[1];
    c->val[2] = a->val[2] * b->val[2];
    c->val[3] = a->val[3] * b->val[3];
}

void had_mat2(mat2 *a, mat2 *b, mat2 *c)
{
    c->val[0] = a->val[0] * b->val[0];
    c->val[1] = a->val[1] * b->val[1];
    c->val[2] = a->val[2] * b->val[2];
    c->val[3] = a->val[3] * b->val[3];
}

void had_mat3(mat3 *a, mat3 *b, mat3 *c)
{
    c->val[0] = a->val[0] * b->val[0];
    c->val[1] = a->val[1] * b->val[1];
    c->val[2] = a->val[2] * b->val[2];
    c->val[3] = a->val[3] * b->val[3];
    c->val[4] = a->val[4] * b->val[4];
    c->val[5] = a->val[5] * b->val[5];
    c->val[6] = a->val[6] * b->val[6];
    c->val[7] = a->val[7] * b->val[7];
    c->val[8] = a->val[8] * b->val[8];
}

void had_mat4(mat4 *a, mat4 *b, mat4 *c)
{
    c->val[0] = a->val[0] * b->val[0];
    c->val[1] = a->val[1] * b->val[1];
    c->val[2] = a->val[2] * b->val[2];
    c->val[3] = a->val[3] * b->val[3];
    c->val[4] = a->val[4] * b->val[4];
    c->val[5] = a->val[5] * b->val[5];
    c->val[6] = a->val[6] * b->val[6];
    c->val[7] = a->val[7] * b->val[7];
    c->val[8] = a->val[8] * b->val[8];
    c->val[9] = a->val[9] * b->val[9];
    c->val[10] = a->val[10] * b->val[10];
    c->val[11] = a->val[11] * b->val[11];
    c->val[12] = a->val[12] * b->val[12];
    c->val[13] = a->val[13] * b->val[13];
    c->val[14] = a->val[14] * b->val[14];
    c->val[15] = a->val[15] * b->val[15];
}

float dot_vec2(vec2 *a, vec2 *b)
{
    return a->val[0] * b->val[0] +
           a->val[1] * b->val[1];
}

float dot_vec3(vec3 *a, vec3 *b)
{
    return a->val[0] * b->val[0] +
           a->val[1] * b->val[1] +
           a->val[2] * b->val[2];
}

float dot_vec4(vec4 *a, vec4 *b)
{
    return a->val[0] * b->val[0] +
           a->val[1] * b->val[1] +
           a->val[2] * b->val[2] +
           a->val[3] * b->val[3];
}

void dot_mat2(mat2 *a, mat2 *b, mat2 *c)
{
    c->val[ 0] = a->val[ 0]*b->val[ 0] + a->val[ 1]*b->val[ 2];
    c->val[ 1] = a->val[ 0]*b->val[ 1] + a->val[ 1]*b->val[ 3];
    c->val[ 2] = a->val[ 2]*b->val[ 0] + a->val[ 3]*b->val[ 2];
    c->val[ 3] = a->val[ 2]*b->val[ 1] + a->val[ 3]*b->val[ 3];
}

void dot_mat2vec2(mat2 *m, vec2 *v, vec2 *c)
{
    c->val[0] = m->val[ 0]*v->val[0] + m->val[ 1]*v->val[1];
    c->val[1] = m->val[ 2]*v->val[0] + m->val[ 3]*v->val[1];
}

void dot_mat3(mat3 *a, mat3 *b, mat3 *c)
{
    c->val[ 0] = a->val[ 0]*b->val[ 0] + a->val[ 1]*b->val[ 3] + a->val[ 2]*b->val[ 6];
    c->val[ 1] = a->val[ 0]*b->val[ 1] + a->val[ 1]*b->val[ 4] + a->val[ 2]*b->val[ 7];
    c->val[ 2] = a->val[ 0]*b->val[ 2] + a->val[ 1]*b->val[ 5] + a->val[ 2]*b->val[ 8];
    c->val[ 3] = a->val[ 3]*b->val[ 0] + a->val[ 4]*b->val[ 3] + a->val[ 5]*b->val[ 6];
    c->val[ 4] = a->val[ 3]*b->val[ 1] + a->val[ 4]*b->val[ 4] + a->val[ 5]*b->val[ 7];
    c->val[ 5] = a->val[ 3]*b->val[ 2] + a->val[ 4]*b->val[ 5] + a->val[ 5]*b->val[ 8];
    c->val[ 6] = a->val[ 6]*b->val[ 0] + a->val[ 7]*b->val[ 3] + a->val[ 8]*b->val[ 6];
    c->val[ 7] = a->val[ 6]*b->val[ 1] + a->val[ 7]*b->val[ 4] + a->val[ 8]*b->val[ 7];
    c->val[ 8] = a->val[ 6]*b->val[ 2] + a->val[ 7]*b->val[ 5] + a->val[ 8]*b->val[ 8];
}

void dot_mat3vec3(mat3 *m, vec3 *v, vec3 *c)
{
    c->val[0] = m->val[ 0]*v->val[0] + m->val[ 1]*v->val[1] + m->val[ 2]*v->val[2];
    c->val[1] = m->val[ 3]*v->val[0] + m->val[ 4]*v->val[1] + m->val[ 5]*v->val[2];
    c->val[2] = m->val[ 6]*v->val[0] + m->val[ 7]*v->val[1] + m->val[ 8]*v->val[2];
}

void dot_mat4(mat4 *a, mat4 *b, mat4 *c)
{
    c->val[ 0] = a->val[ 0]*b->val[ 0] + a->val[ 1]*b->val[ 4] + a->val[ 2]*b->val[ 8] + a->val[ 3]*b->val[12];
    c->val[ 1] = a->val[ 0]*b->val[ 1] + a->val[ 1]*b->val[ 5] + a->val[ 2]*b->val[ 9] + a->val[ 3]*b->val[13];
    c->val[ 2] = a->val[ 0]*b->val[ 2] + a->val[ 1]*b->val[ 6] + a->val[ 2]*b->val[10] + a->val[ 3]*b->val[14];
    c->val[ 3] = a->val[ 0]*b->val[ 3] + a->val[ 1]*b->val[ 7] + a->val[ 2]*b->val[11] + a->val[ 3]*b->val[15];
    c->val[ 4] = a->val[ 4]*b->val[ 0] + a->val[ 5]*b->val[ 4] + a->val[ 6]*b->val[ 8] + a->val[ 7]*b->val[12];
    c->val[ 5] = a->val[ 4]*b->val[ 1] + a->val[ 5]*b->val[ 5] + a->val[ 6]*b->val[ 9] + a->val[ 7]*b->val[13];
    c->val[ 6] = a->val[ 4]*b->val[ 2] + a->val[ 5]*b->val[ 6] + a->val[ 6]*b->val[10] + a->val[ 7]*b->val[14];
    c->val[ 7] = a->val[ 4]*b->val[ 3] + a->val[ 5]*b->val[ 7] + a->val[ 6]*b->val[11] + a->val[ 7]*b->val[15];
    c->val[ 8] = a->val[ 8]*b->val[ 0] + a->val[ 9]*b->val[ 4] + a->val[10]*b->val[ 8] + a->val[11]*b->val[12];
    c->val[ 9] = a->val[ 8]*b->val[ 1] + a->val[ 9]*b->val[ 5] + a->val[10]*b->val[ 9] + a->val[11]*b->val[13];
    c->val[10] = a->val[ 8]*b->val[ 2] + a->val[ 9]*b->val[ 6] + a->val[10]*b->val[10] + a->val[11]*b->val[14];
    c->val[11] = a->val[ 8]*b->val[ 3] + a->val[ 9]*b->val[ 7] + a->val[10]*b->val[11] + a->val[11]*b->val[15];
    c->val[12] = a->val[12]*b->val[ 0] + a->val[13]*b->val[ 4] + a->val[14]*b->val[ 8] + a->val[15]*b->val[12];
    c->val[13] = a->val[12]*b->val[ 1] + a->val[13]*b->val[ 5] + a->val[14]*b->val[ 9] + a->val[15]*b->val[13];
    c->val[14] = a->val[12]*b->val[ 2] + a->val[13]*b->val[ 6] + a->val[14]*b->val[10] + a->val[15]*b->val[14];
    c->val[15] = a->val[12]*b->val[ 3] + a->val[13]*b->val[ 7] + a->val[14]*b->val[11] + a->val[15]*b->val[15];
}

void dot_mat4vec4(mat4 *m, vec4 *v, vec4 *c)
{
    c->val[0] = m->val[ 0]*v->val[0] + m->val[ 1]*v->val[1] + m->val[ 2]*v->val[2] + m->val[ 3]*v->val[3];
    c->val[1] = m->val[ 4]*v->val[0] + m->val[ 5]*v->val[1] + m->val[ 6]*v->val[2] + m->val[ 7]*v->val[3];
    c->val[2] = m->val[ 8]*v->val[0] + m->val[ 9]*v->val[1] + m->val[10]*v->val[2] + m->val[11]*v->val[3];
    c->val[3] = m->val[12]*v->val[0] + m->val[13]*v->val[1] + m->val[14]*v->val[2] + m->val[15]*v->val[3];
}
