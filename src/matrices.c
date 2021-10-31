/*
 * Abandon all hope, ye who enter here.
 *
 * With the exception of the matrix inversion functions, the contents of this
 * file are generated code. If you want to make any significant changes, you
 * should probably consider editing and re-running the script.
 */

#include "matrices.h"
#include <math.h> /* fabs */

void attyr_init_vec2(attyr_vec2 *v, float x, float y)
{
	v->x = x;
	v->y = y;
}

void attyr_init_vec3(attyr_vec3 *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void attyr_init_vec4(attyr_vec4 *v, float x, float y, float z, float w)
{
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
}

void attyr_init_mat2x2(attyr_mat2x2 *m, attyr_vec2 *col1, attyr_vec2 *col2)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
}

void attyr_init_mat2x3(attyr_mat2x3 *m, attyr_vec2 *col1, attyr_vec2 *col2, attyr_vec2 *col3)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m13 = col3->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m23 = col3->y;
}

void attyr_init_mat2x4(attyr_mat2x4 *m, attyr_vec2 *col1, attyr_vec2 *col2, attyr_vec2 *col3, attyr_vec2 *col4)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m13 = col3->x;
	m->m14 = col4->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m23 = col3->y;
	m->m24 = col4->y;
}

void attyr_init_mat3x2(attyr_mat3x2 *m, attyr_vec3 *col1, attyr_vec3 *col2)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m31 = col1->z;
	m->m32 = col2->z;
}

void attyr_init_mat3x3(attyr_mat3x3 *m, attyr_vec3 *col1, attyr_vec3 *col2, attyr_vec3 *col3)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m13 = col3->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m23 = col3->y;
	m->m31 = col1->z;
	m->m32 = col2->z;
	m->m33 = col3->z;
}

void attyr_init_mat3x4(attyr_mat3x4 *m, attyr_vec3 *col1, attyr_vec3 *col2, attyr_vec3 *col3, attyr_vec3 *col4)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m13 = col3->x;
	m->m14 = col4->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m23 = col3->y;
	m->m24 = col4->y;
	m->m31 = col1->z;
	m->m32 = col2->z;
	m->m33 = col3->z;
	m->m34 = col4->z;
}

void attyr_init_mat4x2(attyr_mat4x2 *m, attyr_vec4 *col1, attyr_vec4 *col2)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m31 = col1->z;
	m->m32 = col2->z;
	m->m41 = col1->w;
	m->m42 = col2->w;
}

void attyr_init_mat4x3(attyr_mat4x3 *m, attyr_vec4 *col1, attyr_vec4 *col2, attyr_vec4 *col3)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m13 = col3->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m23 = col3->y;
	m->m31 = col1->z;
	m->m32 = col2->z;
	m->m33 = col3->z;
	m->m41 = col1->w;
	m->m42 = col2->w;
	m->m43 = col3->w;
}

void attyr_init_mat4x4(attyr_mat4x4 *m, attyr_vec4 *col1, attyr_vec4 *col2, attyr_vec4 *col3, attyr_vec4 *col4)
{
	m->m11 = col1->x;
	m->m12 = col2->x;
	m->m13 = col3->x;
	m->m14 = col4->x;
	m->m21 = col1->y;
	m->m22 = col2->y;
	m->m23 = col3->y;
	m->m24 = col4->y;
	m->m31 = col1->z;
	m->m32 = col2->z;
	m->m33 = col3->z;
	m->m34 = col4->z;
	m->m41 = col1->w;
	m->m42 = col2->w;
	m->m43 = col3->w;
	m->m44 = col4->w;
}

void attyr_diag_mat2x2(float d, attyr_mat2x2 *dst)
{
	dst->m11 = d;
	dst->m12 = 0;
	dst->m21 = 0;
	dst->m22 = d;
}

void attyr_diag_mat3x3(float d, attyr_mat3x3 *dst)
{
	dst->m11 = d;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m21 = 0;
	dst->m22 = d;
	dst->m23 = 0;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = d;
}

void attyr_diag_mat4x4(float d, attyr_mat4x4 *dst)
{
	dst->m11 = d;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m14 = 0;
	dst->m21 = 0;
	dst->m22 = d;
	dst->m23 = 0;
	dst->m24 = 0;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = d;
	dst->m34 = 0;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = d;
}

void attyr_dup_vec2(attyr_vec2 *src, attyr_vec2 *dst)
{
	*dst = *src;
}

void attyr_dup_vec3(attyr_vec3 *src, attyr_vec3 *dst)
{
	*dst = *src;
}

void attyr_dup_vec4(attyr_vec4 *src, attyr_vec4 *dst)
{
	*dst = *src;
}

void attyr_dup_mat2x2(attyr_mat2x2 *src, attyr_mat2x2 *dst)
{
	*dst = *src;
}

void attyr_dup_mat2x3(attyr_mat2x3 *src, attyr_mat2x3 *dst)
{
	*dst = *src;
}

void attyr_dup_mat2x4(attyr_mat2x4 *src, attyr_mat2x4 *dst)
{
	*dst = *src;
}

void attyr_dup_mat3x2(attyr_mat3x2 *src, attyr_mat3x2 *dst)
{
	*dst = *src;
}

void attyr_dup_mat3x3(attyr_mat3x3 *src, attyr_mat3x3 *dst)
{
	*dst = *src;
}

void attyr_dup_mat3x4(attyr_mat3x4 *src, attyr_mat3x4 *dst)
{
	*dst = *src;
}

void attyr_dup_mat4x2(attyr_mat4x2 *src, attyr_mat4x2 *dst)
{
	*dst = *src;
}

void attyr_dup_mat4x3(attyr_mat4x3 *src, attyr_mat4x3 *dst)
{
	*dst = *src;
}

void attyr_dup_mat4x4(attyr_mat4x4 *src, attyr_mat4x4 *dst)
{
	*dst = *src;
}

float attyr_len_vec2(attyr_vec2 *v)
{
    return sqrt(v->x*v->x + v->y*v->y);
}

float attyr_len_vec3(attyr_vec3 *v)
{
    return sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
}

float attyr_len_vec4(attyr_vec4 *v)
{
    return sqrt(v->x*v->x + v->y*v->y + v->z*v->z + v->w*v->w);
}

void attyr_scale_vec2(attyr_vec2 *v, float s)
{
	v->x *= s;
	v->y *= s;
}

void attyr_scale_vec3(attyr_vec3 *v, float s)
{
	v->x *= s;
	v->y *= s;
	v->z *= s;
}

void attyr_scale_vec4(attyr_vec4 *v, float s)
{
	v->x *= s;
	v->y *= s;
	v->z *= s;
	v->w *= s;
}

float attyr_normalize_vec2(attyr_vec2 *v)
{
	float len = attyr_len_vec2(v);
	if (len != 0) {
		attyr_scale_vec2(v, 1/len);
		return 1;
	}
	return 0;
}

float attyr_normalize_vec3(attyr_vec3 *v)
{
	float len = attyr_len_vec3(v);
	if (len != 0) {
		attyr_scale_vec3(v, 1/len);
		return 1;
	}
	return 0;
}

float attyr_normalize_vec4(attyr_vec4 *v)
{
	float len = attyr_len_vec4(v);
	if (len != 0) {
		attyr_scale_vec4(v, 1/len);
		return 1;
	}
	return 0;
}

void attyr_scale_mat2x2(attyr_mat2x2 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m21 *= s;
	m->m22 *= s;
}

void attyr_scale_mat2x3(attyr_mat2x3 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m13 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m23 *= s;
}

void attyr_scale_mat2x4(attyr_mat2x4 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m13 *= s;
	m->m14 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m23 *= s;
	m->m24 *= s;
}

void attyr_scale_mat3x2(attyr_mat3x2 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m31 *= s;
	m->m32 *= s;
}

void attyr_scale_mat3x3(attyr_mat3x3 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m13 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m23 *= s;
	m->m31 *= s;
	m->m32 *= s;
	m->m33 *= s;
}

void attyr_scale_mat3x4(attyr_mat3x4 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m13 *= s;
	m->m14 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m23 *= s;
	m->m24 *= s;
	m->m31 *= s;
	m->m32 *= s;
	m->m33 *= s;
	m->m34 *= s;
}

void attyr_scale_mat4x2(attyr_mat4x2 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m31 *= s;
	m->m32 *= s;
	m->m41 *= s;
	m->m42 *= s;
}

void attyr_scale_mat4x3(attyr_mat4x3 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m13 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m23 *= s;
	m->m31 *= s;
	m->m32 *= s;
	m->m33 *= s;
	m->m41 *= s;
	m->m42 *= s;
	m->m43 *= s;
}

void attyr_scale_mat4x4(attyr_mat4x4 *m, float s)
{
	m->m11 *= s;
	m->m12 *= s;
	m->m13 *= s;
	m->m14 *= s;
	m->m21 *= s;
	m->m22 *= s;
	m->m23 *= s;
	m->m24 *= s;
	m->m31 *= s;
	m->m32 *= s;
	m->m33 *= s;
	m->m34 *= s;
	m->m41 *= s;
	m->m42 *= s;
	m->m43 *= s;
	m->m44 *= s;
}

void attyr_add_vec2(attyr_vec2 *a, attyr_vec2 *b, attyr_vec2 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
}

void attyr_add_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
}

void attyr_add_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
	c->w = a->w + b->w;
}

void attyr_add_mat2x2(attyr_mat2x2 *a, attyr_mat2x2 *b, attyr_mat2x2 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
}

void attyr_add_mat2x3(attyr_mat2x3 *a, attyr_mat2x3 *b, attyr_mat2x3 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m13 = a->m13 + b->m13;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m23 = a->m23 + b->m23;
}

void attyr_add_mat2x4(attyr_mat2x4 *a, attyr_mat2x4 *b, attyr_mat2x4 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m13 = a->m13 + b->m13;
	c->m14 = a->m14 + b->m14;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m23 = a->m23 + b->m23;
	c->m24 = a->m24 + b->m24;
}

void attyr_add_mat3x2(attyr_mat3x2 *a, attyr_mat3x2 *b, attyr_mat3x2 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m31 = a->m31 + b->m31;
	c->m32 = a->m32 + b->m32;
}

void attyr_add_mat3x3(attyr_mat3x3 *a, attyr_mat3x3 *b, attyr_mat3x3 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m13 = a->m13 + b->m13;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m23 = a->m23 + b->m23;
	c->m31 = a->m31 + b->m31;
	c->m32 = a->m32 + b->m32;
	c->m33 = a->m33 + b->m33;
}

void attyr_add_mat3x4(attyr_mat3x4 *a, attyr_mat3x4 *b, attyr_mat3x4 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m13 = a->m13 + b->m13;
	c->m14 = a->m14 + b->m14;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m23 = a->m23 + b->m23;
	c->m24 = a->m24 + b->m24;
	c->m31 = a->m31 + b->m31;
	c->m32 = a->m32 + b->m32;
	c->m33 = a->m33 + b->m33;
	c->m34 = a->m34 + b->m34;
}

void attyr_add_mat4x2(attyr_mat4x2 *a, attyr_mat4x2 *b, attyr_mat4x2 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m31 = a->m31 + b->m31;
	c->m32 = a->m32 + b->m32;
	c->m41 = a->m41 + b->m41;
	c->m42 = a->m42 + b->m42;
}

void attyr_add_mat4x3(attyr_mat4x3 *a, attyr_mat4x3 *b, attyr_mat4x3 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m13 = a->m13 + b->m13;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m23 = a->m23 + b->m23;
	c->m31 = a->m31 + b->m31;
	c->m32 = a->m32 + b->m32;
	c->m33 = a->m33 + b->m33;
	c->m41 = a->m41 + b->m41;
	c->m42 = a->m42 + b->m42;
	c->m43 = a->m43 + b->m43;
}

void attyr_add_mat4x4(attyr_mat4x4 *a, attyr_mat4x4 *b, attyr_mat4x4 *c)
{
	c->m11 = a->m11 + b->m11;
	c->m12 = a->m12 + b->m12;
	c->m13 = a->m13 + b->m13;
	c->m14 = a->m14 + b->m14;
	c->m21 = a->m21 + b->m21;
	c->m22 = a->m22 + b->m22;
	c->m23 = a->m23 + b->m23;
	c->m24 = a->m24 + b->m24;
	c->m31 = a->m31 + b->m31;
	c->m32 = a->m32 + b->m32;
	c->m33 = a->m33 + b->m33;
	c->m34 = a->m34 + b->m34;
	c->m41 = a->m41 + b->m41;
	c->m42 = a->m42 + b->m42;
	c->m43 = a->m43 + b->m43;
	c->m44 = a->m44 + b->m44;
}

void attyr_sub_vec2(attyr_vec2 *a, attyr_vec2 *b, attyr_vec2 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
}

void attyr_sub_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
}

void attyr_sub_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
	c->w = a->w - b->w;
}

void attyr_sub_mat2x2(attyr_mat2x2 *a, attyr_mat2x2 *b, attyr_mat2x2 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
}

void attyr_sub_mat2x3(attyr_mat2x3 *a, attyr_mat2x3 *b, attyr_mat2x3 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m13 = a->m13 - b->m13;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m23 = a->m23 - b->m23;
}

void attyr_sub_mat2x4(attyr_mat2x4 *a, attyr_mat2x4 *b, attyr_mat2x4 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m13 = a->m13 - b->m13;
	c->m14 = a->m14 - b->m14;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m23 = a->m23 - b->m23;
	c->m24 = a->m24 - b->m24;
}

void attyr_sub_mat3x2(attyr_mat3x2 *a, attyr_mat3x2 *b, attyr_mat3x2 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m31 = a->m31 - b->m31;
	c->m32 = a->m32 - b->m32;
}

void attyr_sub_mat3x3(attyr_mat3x3 *a, attyr_mat3x3 *b, attyr_mat3x3 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m13 = a->m13 - b->m13;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m23 = a->m23 - b->m23;
	c->m31 = a->m31 - b->m31;
	c->m32 = a->m32 - b->m32;
	c->m33 = a->m33 - b->m33;
}

void attyr_sub_mat3x4(attyr_mat3x4 *a, attyr_mat3x4 *b, attyr_mat3x4 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m13 = a->m13 - b->m13;
	c->m14 = a->m14 - b->m14;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m23 = a->m23 - b->m23;
	c->m24 = a->m24 - b->m24;
	c->m31 = a->m31 - b->m31;
	c->m32 = a->m32 - b->m32;
	c->m33 = a->m33 - b->m33;
	c->m34 = a->m34 - b->m34;
}

void attyr_sub_mat4x2(attyr_mat4x2 *a, attyr_mat4x2 *b, attyr_mat4x2 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m31 = a->m31 - b->m31;
	c->m32 = a->m32 - b->m32;
	c->m41 = a->m41 - b->m41;
	c->m42 = a->m42 - b->m42;
}

void attyr_sub_mat4x3(attyr_mat4x3 *a, attyr_mat4x3 *b, attyr_mat4x3 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m13 = a->m13 - b->m13;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m23 = a->m23 - b->m23;
	c->m31 = a->m31 - b->m31;
	c->m32 = a->m32 - b->m32;
	c->m33 = a->m33 - b->m33;
	c->m41 = a->m41 - b->m41;
	c->m42 = a->m42 - b->m42;
	c->m43 = a->m43 - b->m43;
}

void attyr_sub_mat4x4(attyr_mat4x4 *a, attyr_mat4x4 *b, attyr_mat4x4 *c)
{
	c->m11 = a->m11 - b->m11;
	c->m12 = a->m12 - b->m12;
	c->m13 = a->m13 - b->m13;
	c->m14 = a->m14 - b->m14;
	c->m21 = a->m21 - b->m21;
	c->m22 = a->m22 - b->m22;
	c->m23 = a->m23 - b->m23;
	c->m24 = a->m24 - b->m24;
	c->m31 = a->m31 - b->m31;
	c->m32 = a->m32 - b->m32;
	c->m33 = a->m33 - b->m33;
	c->m34 = a->m34 - b->m34;
	c->m41 = a->m41 - b->m41;
	c->m42 = a->m42 - b->m42;
	c->m43 = a->m43 - b->m43;
	c->m44 = a->m44 - b->m44;
}

float attyr_dot_vec2(attyr_vec2 *a, attyr_vec2 *b)
{
	return a->x*b->x + a->y*b->y;
}

float attyr_dot_vec3(attyr_vec3 *a, attyr_vec3 *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z;
}

float attyr_dot_vec4(attyr_vec4 *a, attyr_vec4 *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z + a->w*b->w;
}

void attyr_cross_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *dst)
{
	float ax = a->x, ay = a->y, az = a->z,
		  bx = b->x, by = b->y, bz = b->z;

	dst->x = ay*bz - az*by;
    dst->y = az*bx - ax*bz;
	dst->z = ax*by - ay*bx;
}

void attyr_mult_mat2x2_vec2(attyr_mat2x2 *m, attyr_vec2 *v, attyr_vec2 *dst)
{
	float vx = v->x, vy = v->y;

	dst->x = m->m11*vx + m->m12*vy;
	dst->y = m->m21*vx + m->m22*vy;
}

void attyr_mult_mat2x3_vec3(attyr_mat2x3 *m, attyr_vec3 *v, attyr_vec2 *dst)
{
	float vx = v->x, vy = v->y, vz = v->z;

	dst->x = m->m11*vx + m->m12*vy + m->m13*vz;
	dst->y = m->m21*vx + m->m22*vy + m->m23*vz;
}

void attyr_mult_mat2x4_vec4(attyr_mat2x4 *m, attyr_vec4 *v, attyr_vec2 *dst)
{
	float vx = v->x, vy = v->y, vz = v->z, vw = v->w;

	dst->x = m->m11*vx + m->m12*vy + m->m13*vz + m->m14*vw;
	dst->y = m->m21*vx + m->m22*vy + m->m23*vz + m->m24*vw;
}

void attyr_mult_mat3x2_vec2(attyr_mat3x2 *m, attyr_vec2 *v, attyr_vec3 *dst)
{
	float vx = v->x, vy = v->y;

	dst->x = m->m11*vx + m->m12*vy;
	dst->y = m->m21*vx + m->m22*vy;
	dst->z = m->m31*vx + m->m32*vy;
}

void attyr_mult_mat3x3_vec3(attyr_mat3x3 *m, attyr_vec3 *v, attyr_vec3 *dst)
{
	float vx = v->x, vy = v->y, vz = v->z;

	dst->x = m->m11*vx + m->m12*vy + m->m13*vz;
	dst->y = m->m21*vx + m->m22*vy + m->m23*vz;
	dst->z = m->m31*vx + m->m32*vy + m->m33*vz;
}

void attyr_mult_mat3x4_vec4(attyr_mat3x4 *m, attyr_vec4 *v, attyr_vec3 *dst)
{
	float vx = v->x, vy = v->y, vz = v->z, vw = v->w;

	dst->x = m->m11*vx + m->m12*vy + m->m13*vz + m->m14*vw;
	dst->y = m->m21*vx + m->m22*vy + m->m23*vz + m->m24*vw;
	dst->z = m->m31*vx + m->m32*vy + m->m33*vz + m->m34*vw;
}

void attyr_mult_mat4x2_vec2(attyr_mat4x2 *m, attyr_vec2 *v, attyr_vec4 *dst)
{
	float vx = v->x, vy = v->y;

	dst->x = m->m11*vx + m->m12*vy;
	dst->y = m->m21*vx + m->m22*vy;
	dst->z = m->m31*vx + m->m32*vy;
	dst->w = m->m41*vx + m->m42*vy;
}

void attyr_mult_mat4x3_vec3(attyr_mat4x3 *m, attyr_vec3 *v, attyr_vec4 *dst)
{
	float vx = v->x, vy = v->y, vz = v->z;

	dst->x = m->m11*vx + m->m12*vy + m->m13*vz;
	dst->y = m->m21*vx + m->m22*vy + m->m23*vz;
	dst->z = m->m31*vx + m->m32*vy + m->m33*vz;
	dst->w = m->m41*vx + m->m42*vy + m->m43*vz;
}

void attyr_mult_mat4x4_vec4(attyr_mat4x4 *m, attyr_vec4 *v, attyr_vec4 *dst)
{
	float vx = v->x, vy = v->y, vz = v->z, vw = v->w;

	dst->x = m->m11*vx + m->m12*vy + m->m13*vz + m->m14*vw;
	dst->y = m->m21*vx + m->m22*vy + m->m23*vz + m->m24*vw;
	dst->z = m->m31*vx + m->m32*vy + m->m33*vz + m->m34*vw;
	dst->w = m->m41*vx + m->m42*vy + m->m43*vz + m->m44*vw;
}

void attyr_mult_mat2x2_2x2(attyr_mat2x2 *a, attyr_mat2x2 *b, attyr_mat2x2 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
}

void attyr_mult_mat2x2_2x3(attyr_mat2x2 *a, attyr_mat2x3 *b, attyr_mat2x3 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m13 = a11*b13 + a12*b23;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m23 = a21*b13 + a22*b23;
}

void attyr_mult_mat2x2_2x4(attyr_mat2x2 *a, attyr_mat2x4 *b, attyr_mat2x4 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m13 = a11*b13 + a12*b23;
	dst->m14 = a11*b14 + a12*b24;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m23 = a21*b13 + a22*b23;
	dst->m24 = a21*b14 + a22*b24;
}

void attyr_mult_mat2x3_3x2(attyr_mat2x3 *a, attyr_mat3x2 *b, attyr_mat2x2 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22,
	      b31 = b->m31, b32 = b->m32;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
}

void attyr_mult_mat2x3_3x3(attyr_mat2x3 *a, attyr_mat3x3 *b, attyr_mat2x3 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m13 = a11*b13 + a12*b23 + a13*b33;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m23 = a21*b13 + a22*b23 + a23*b33;
}

void attyr_mult_mat2x3_3x4(attyr_mat2x3 *a, attyr_mat3x4 *b, attyr_mat2x4 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33, b34 = b->m34;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m13 = a11*b13 + a12*b23 + a13*b33;
	dst->m14 = a11*b14 + a12*b24 + a13*b34;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m23 = a21*b13 + a22*b23 + a23*b33;
	dst->m24 = a21*b14 + a22*b24 + a23*b34;
}

void attyr_mult_mat2x4_4x2(attyr_mat2x4 *a, attyr_mat4x2 *b, attyr_mat2x2 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22,
	      b31 = b->m31, b32 = b->m32,
	      b41 = b->m41, b42 = b->m42;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
}

void attyr_mult_mat2x4_4x3(attyr_mat2x4 *a, attyr_mat4x3 *b, attyr_mat2x3 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33,
	      b41 = b->m41, b42 = b->m42, b43 = b->m43;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m13 = a11*b13 + a12*b23 + a13*b33 + a14*b43;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m23 = a21*b13 + a22*b23 + a23*b33 + a24*b43;
}

void attyr_mult_mat2x4_4x4(attyr_mat2x4 *a, attyr_mat4x4 *b, attyr_mat2x4 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33, b34 = b->m34,
	      b41 = b->m41, b42 = b->m42, b43 = b->m43, b44 = b->m44;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m13 = a11*b13 + a12*b23 + a13*b33 + a14*b43;
	dst->m14 = a11*b14 + a12*b24 + a13*b34 + a14*b44;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m23 = a21*b13 + a22*b23 + a23*b33 + a24*b43;
	dst->m24 = a21*b14 + a22*b24 + a23*b34 + a24*b44;
}

void attyr_mult_mat3x2_2x2(attyr_mat3x2 *a, attyr_mat2x2 *b, attyr_mat3x2 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      a31 = a->m31, a32 = a->m32,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m31 = a31*b11 + a32*b21;
	dst->m32 = a31*b12 + a32*b22;
}

void attyr_mult_mat3x2_2x3(attyr_mat3x2 *a, attyr_mat2x3 *b, attyr_mat3x3 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      a31 = a->m31, a32 = a->m32,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m13 = a11*b13 + a12*b23;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m23 = a21*b13 + a22*b23;
	dst->m31 = a31*b11 + a32*b21;
	dst->m32 = a31*b12 + a32*b22;
	dst->m33 = a31*b13 + a32*b23;
}

void attyr_mult_mat3x2_2x4(attyr_mat3x2 *a, attyr_mat2x4 *b, attyr_mat3x4 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      a31 = a->m31, a32 = a->m32,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m13 = a11*b13 + a12*b23;
	dst->m14 = a11*b14 + a12*b24;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m23 = a21*b13 + a22*b23;
	dst->m24 = a21*b14 + a22*b24;
	dst->m31 = a31*b11 + a32*b21;
	dst->m32 = a31*b12 + a32*b22;
	dst->m33 = a31*b13 + a32*b23;
	dst->m34 = a31*b14 + a32*b24;
}

void attyr_mult_mat3x3_3x2(attyr_mat3x3 *a, attyr_mat3x2 *b, attyr_mat3x2 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22,
	      b31 = b->m31, b32 = b->m32;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m31 = a31*b11 + a32*b21 + a33*b31;
	dst->m32 = a31*b12 + a32*b22 + a33*b32;
}

void attyr_mult_mat3x3_3x3(attyr_mat3x3 *a, attyr_mat3x3 *b, attyr_mat3x3 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m13 = a11*b13 + a12*b23 + a13*b33;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m23 = a21*b13 + a22*b23 + a23*b33;
	dst->m31 = a31*b11 + a32*b21 + a33*b31;
	dst->m32 = a31*b12 + a32*b22 + a33*b32;
	dst->m33 = a31*b13 + a32*b23 + a33*b33;
}

void attyr_mult_mat3x3_3x4(attyr_mat3x3 *a, attyr_mat3x4 *b, attyr_mat3x4 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33, b34 = b->m34;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m13 = a11*b13 + a12*b23 + a13*b33;
	dst->m14 = a11*b14 + a12*b24 + a13*b34;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m23 = a21*b13 + a22*b23 + a23*b33;
	dst->m24 = a21*b14 + a22*b24 + a23*b34;
	dst->m31 = a31*b11 + a32*b21 + a33*b31;
	dst->m32 = a31*b12 + a32*b22 + a33*b32;
	dst->m33 = a31*b13 + a32*b23 + a33*b33;
	dst->m34 = a31*b14 + a32*b24 + a33*b34;
}

void attyr_mult_mat3x4_4x2(attyr_mat3x4 *a, attyr_mat4x2 *b, attyr_mat3x2 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33, a34 = a->m34,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22,
	      b31 = b->m31, b32 = b->m32,
	      b41 = b->m41, b42 = b->m42;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m31 = a31*b11 + a32*b21 + a33*b31 + a34*b41;
	dst->m32 = a31*b12 + a32*b22 + a33*b32 + a34*b42;
}

void attyr_mult_mat3x4_4x3(attyr_mat3x4 *a, attyr_mat4x3 *b, attyr_mat3x3 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33, a34 = a->m34,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33,
	      b41 = b->m41, b42 = b->m42, b43 = b->m43;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m13 = a11*b13 + a12*b23 + a13*b33 + a14*b43;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m23 = a21*b13 + a22*b23 + a23*b33 + a24*b43;
	dst->m31 = a31*b11 + a32*b21 + a33*b31 + a34*b41;
	dst->m32 = a31*b12 + a32*b22 + a33*b32 + a34*b42;
	dst->m33 = a31*b13 + a32*b23 + a33*b33 + a34*b43;
}

void attyr_mult_mat3x4_4x4(attyr_mat3x4 *a, attyr_mat4x4 *b, attyr_mat3x4 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33, a34 = a->m34,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33, b34 = b->m34,
	      b41 = b->m41, b42 = b->m42, b43 = b->m43, b44 = b->m44;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m13 = a11*b13 + a12*b23 + a13*b33 + a14*b43;
	dst->m14 = a11*b14 + a12*b24 + a13*b34 + a14*b44;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m23 = a21*b13 + a22*b23 + a23*b33 + a24*b43;
	dst->m24 = a21*b14 + a22*b24 + a23*b34 + a24*b44;
	dst->m31 = a31*b11 + a32*b21 + a33*b31 + a34*b41;
	dst->m32 = a31*b12 + a32*b22 + a33*b32 + a34*b42;
	dst->m33 = a31*b13 + a32*b23 + a33*b33 + a34*b43;
	dst->m34 = a31*b14 + a32*b24 + a33*b34 + a34*b44;
}

void attyr_mult_mat4x2_2x2(attyr_mat4x2 *a, attyr_mat2x2 *b, attyr_mat4x2 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      a31 = a->m31, a32 = a->m32,
	      a41 = a->m41, a42 = a->m42,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m31 = a31*b11 + a32*b21;
	dst->m32 = a31*b12 + a32*b22;
	dst->m41 = a41*b11 + a42*b21;
	dst->m42 = a41*b12 + a42*b22;
}

void attyr_mult_mat4x2_2x3(attyr_mat4x2 *a, attyr_mat2x3 *b, attyr_mat4x3 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      a31 = a->m31, a32 = a->m32,
	      a41 = a->m41, a42 = a->m42,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m13 = a11*b13 + a12*b23;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m23 = a21*b13 + a22*b23;
	dst->m31 = a31*b11 + a32*b21;
	dst->m32 = a31*b12 + a32*b22;
	dst->m33 = a31*b13 + a32*b23;
	dst->m41 = a41*b11 + a42*b21;
	dst->m42 = a41*b12 + a42*b22;
	dst->m43 = a41*b13 + a42*b23;
}

void attyr_mult_mat4x2_2x4(attyr_mat4x2 *a, attyr_mat2x4 *b, attyr_mat4x4 *dst)
{
	float a11 = a->m11, a12 = a->m12,
	      a21 = a->m21, a22 = a->m22,
	      a31 = a->m31, a32 = a->m32,
	      a41 = a->m41, a42 = a->m42,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24;

	dst->m11 = a11*b11 + a12*b21;
	dst->m12 = a11*b12 + a12*b22;
	dst->m13 = a11*b13 + a12*b23;
	dst->m14 = a11*b14 + a12*b24;
	dst->m21 = a21*b11 + a22*b21;
	dst->m22 = a21*b12 + a22*b22;
	dst->m23 = a21*b13 + a22*b23;
	dst->m24 = a21*b14 + a22*b24;
	dst->m31 = a31*b11 + a32*b21;
	dst->m32 = a31*b12 + a32*b22;
	dst->m33 = a31*b13 + a32*b23;
	dst->m34 = a31*b14 + a32*b24;
	dst->m41 = a41*b11 + a42*b21;
	dst->m42 = a41*b12 + a42*b22;
	dst->m43 = a41*b13 + a42*b23;
	dst->m44 = a41*b14 + a42*b24;
}

void attyr_mult_mat4x3_3x2(attyr_mat4x3 *a, attyr_mat3x2 *b, attyr_mat4x2 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33,
	      a41 = a->m41, a42 = a->m42, a43 = a->m43,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22,
	      b31 = b->m31, b32 = b->m32;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m31 = a31*b11 + a32*b21 + a33*b31;
	dst->m32 = a31*b12 + a32*b22 + a33*b32;
	dst->m41 = a41*b11 + a42*b21 + a43*b31;
	dst->m42 = a41*b12 + a42*b22 + a43*b32;
}

void attyr_mult_mat4x3_3x3(attyr_mat4x3 *a, attyr_mat3x3 *b, attyr_mat4x3 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33,
	      a41 = a->m41, a42 = a->m42, a43 = a->m43,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m13 = a11*b13 + a12*b23 + a13*b33;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m23 = a21*b13 + a22*b23 + a23*b33;
	dst->m31 = a31*b11 + a32*b21 + a33*b31;
	dst->m32 = a31*b12 + a32*b22 + a33*b32;
	dst->m33 = a31*b13 + a32*b23 + a33*b33;
	dst->m41 = a41*b11 + a42*b21 + a43*b31;
	dst->m42 = a41*b12 + a42*b22 + a43*b32;
	dst->m43 = a41*b13 + a42*b23 + a43*b33;
}

void attyr_mult_mat4x3_3x4(attyr_mat4x3 *a, attyr_mat3x4 *b, attyr_mat4x4 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33,
	      a41 = a->m41, a42 = a->m42, a43 = a->m43,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33, b34 = b->m34;

	dst->m11 = a11*b11 + a12*b21 + a13*b31;
	dst->m12 = a11*b12 + a12*b22 + a13*b32;
	dst->m13 = a11*b13 + a12*b23 + a13*b33;
	dst->m14 = a11*b14 + a12*b24 + a13*b34;
	dst->m21 = a21*b11 + a22*b21 + a23*b31;
	dst->m22 = a21*b12 + a22*b22 + a23*b32;
	dst->m23 = a21*b13 + a22*b23 + a23*b33;
	dst->m24 = a21*b14 + a22*b24 + a23*b34;
	dst->m31 = a31*b11 + a32*b21 + a33*b31;
	dst->m32 = a31*b12 + a32*b22 + a33*b32;
	dst->m33 = a31*b13 + a32*b23 + a33*b33;
	dst->m34 = a31*b14 + a32*b24 + a33*b34;
	dst->m41 = a41*b11 + a42*b21 + a43*b31;
	dst->m42 = a41*b12 + a42*b22 + a43*b32;
	dst->m43 = a41*b13 + a42*b23 + a43*b33;
	dst->m44 = a41*b14 + a42*b24 + a43*b34;
}

void attyr_mult_mat4x4_4x2(attyr_mat4x4 *a, attyr_mat4x2 *b, attyr_mat4x2 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33, a34 = a->m34,
	      a41 = a->m41, a42 = a->m42, a43 = a->m43, a44 = a->m44,
	      b11 = b->m11, b12 = b->m12,
	      b21 = b->m21, b22 = b->m22,
	      b31 = b->m31, b32 = b->m32,
	      b41 = b->m41, b42 = b->m42;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m31 = a31*b11 + a32*b21 + a33*b31 + a34*b41;
	dst->m32 = a31*b12 + a32*b22 + a33*b32 + a34*b42;
	dst->m41 = a41*b11 + a42*b21 + a43*b31 + a44*b41;
	dst->m42 = a41*b12 + a42*b22 + a43*b32 + a44*b42;
}

void attyr_mult_mat4x4_4x3(attyr_mat4x4 *a, attyr_mat4x3 *b, attyr_mat4x3 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33, a34 = a->m34,
	      a41 = a->m41, a42 = a->m42, a43 = a->m43, a44 = a->m44,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33,
	      b41 = b->m41, b42 = b->m42, b43 = b->m43;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m13 = a11*b13 + a12*b23 + a13*b33 + a14*b43;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m23 = a21*b13 + a22*b23 + a23*b33 + a24*b43;
	dst->m31 = a31*b11 + a32*b21 + a33*b31 + a34*b41;
	dst->m32 = a31*b12 + a32*b22 + a33*b32 + a34*b42;
	dst->m33 = a31*b13 + a32*b23 + a33*b33 + a34*b43;
	dst->m41 = a41*b11 + a42*b21 + a43*b31 + a44*b41;
	dst->m42 = a41*b12 + a42*b22 + a43*b32 + a44*b42;
	dst->m43 = a41*b13 + a42*b23 + a43*b33 + a44*b43;
}

void attyr_mult_mat4x4_4x4(attyr_mat4x4 *a, attyr_mat4x4 *b, attyr_mat4x4 *dst)
{
	float a11 = a->m11, a12 = a->m12, a13 = a->m13, a14 = a->m14,
	      a21 = a->m21, a22 = a->m22, a23 = a->m23, a24 = a->m24,
	      a31 = a->m31, a32 = a->m32, a33 = a->m33, a34 = a->m34,
	      a41 = a->m41, a42 = a->m42, a43 = a->m43, a44 = a->m44,
	      b11 = b->m11, b12 = b->m12, b13 = b->m13, b14 = b->m14,
	      b21 = b->m21, b22 = b->m22, b23 = b->m23, b24 = b->m24,
	      b31 = b->m31, b32 = b->m32, b33 = b->m33, b34 = b->m34,
	      b41 = b->m41, b42 = b->m42, b43 = b->m43, b44 = b->m44;

	dst->m11 = a11*b11 + a12*b21 + a13*b31 + a14*b41;
	dst->m12 = a11*b12 + a12*b22 + a13*b32 + a14*b42;
	dst->m13 = a11*b13 + a12*b23 + a13*b33 + a14*b43;
	dst->m14 = a11*b14 + a12*b24 + a13*b34 + a14*b44;
	dst->m21 = a21*b11 + a22*b21 + a23*b31 + a24*b41;
	dst->m22 = a21*b12 + a22*b22 + a23*b32 + a24*b42;
	dst->m23 = a21*b13 + a22*b23 + a23*b33 + a24*b43;
	dst->m24 = a21*b14 + a22*b24 + a23*b34 + a24*b44;
	dst->m31 = a31*b11 + a32*b21 + a33*b31 + a34*b41;
	dst->m32 = a31*b12 + a32*b22 + a33*b32 + a34*b42;
	dst->m33 = a31*b13 + a32*b23 + a33*b33 + a34*b43;
	dst->m34 = a31*b14 + a32*b24 + a33*b34 + a34*b44;
	dst->m41 = a41*b11 + a42*b21 + a43*b31 + a44*b41;
	dst->m42 = a41*b12 + a42*b22 + a43*b32 + a44*b42;
	dst->m43 = a41*b13 + a42*b23 + a43*b33 + a44*b43;
	dst->m44 = a41*b14 + a42*b24 + a43*b34 + a44*b44;
}

float attyr_invert_mat3x3(attyr_mat3x3 *m)
{
    float a = m->m22*m->m33 - m->m23*m->m32,
          b = m->m23*m->m31 - m->m21*m->m33,
          c = m->m21*m->m32 - m->m22*m->m31,
          d = m->m13*m->m32 - m->m12*m->m33,
          e = m->m11*m->m33 - m->m13*m->m31,
          f = m->m12*m->m31 - m->m11*m->m32,
          g = m->m12*m->m23 - m->m13*m->m22,
          h = m->m13*m->m21 - m->m11*m->m23,
          i = m->m11*m->m22 - m->m12*m->m21,
          det = m->m11*a + m->m12*b + m->m13*c;

    if (fabs(det) >= ATTYR_MAT_INV_EPSILON) {
        float s = 1/det;

        m->m11 = s*a; m->m12 = s*d; m->m13 = s*g;
        m->m21 = s*b; m->m22 = s*e; m->m23 = s*h;
        m->m31 = s*c; m->m32 = s*f; m->m33 = s*i;

        return det;
    }

    return 0;
}

void attyr_rotate(attyr_vec3 *axis, float angle, attyr_mat4x4 *dst)
{
	float c = cos(angle), s = sin(angle), t = 1-c;
	float x = axis->x, y = axis->y, z = axis->z;

	dst->m11 = x*x*t + c;
	dst->m12 = y*x*t - z*s;
	dst->m13 = z*x*t + y*s;
	dst->m14 = 0;
	dst->m21 = x*y*t + z*s;
	dst->m22 = y*y*t + c;
	dst->m23 = z*y*t - x*s;
	dst->m24 = 0;
	dst->m31 = x*z*t - y*s;
	dst->m32 = y*z*t + x*s;
	dst->m33 = z*z*t + c;
	dst->m34 = 0;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}

void attyr_rotate_x(float angle, attyr_mat4x4 *dst)
{
	float c = cos(angle), s = sin(angle);

	dst->m11 = 1;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m14 = 0;
	dst->m21 = 0;
	dst->m22 = c;
	dst->m23 = -s;
	dst->m24 = 0;
	dst->m31 = 0;
	dst->m32 = s;
	dst->m33 = c;
	dst->m34 = 0;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}

void attyr_rotate_y(float angle, attyr_mat4x4 *dst)
{
	float c = cos(angle), s = sin(angle);

	dst->m11 = c;
	dst->m12 = 0;
	dst->m13 = s;
	dst->m14 = 0;
	dst->m21 = 0;
	dst->m22 = 1;
	dst->m23 = 0;
	dst->m24 = 0;
	dst->m31 = -s;
	dst->m32 = 0;
	dst->m33 = c;
	dst->m34 = 0;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}

void attyr_rotate_z(float angle, attyr_mat4x4 *dst)
{
	float c = cos(angle), s = sin(angle);

	dst->m11 = c;
	dst->m12 = -s;
	dst->m13 = 0;
	dst->m14 = 0;
	dst->m21 = s;
	dst->m22 = c;
	dst->m23 = 0;
	dst->m24 = 0;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = 1;
	dst->m34 = 0;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}

void attyr_translate(attyr_vec3 *mov, attyr_mat4x4 *dst)
{
	dst->m11 = 1;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m14 = mov->x;
	dst->m21 = 0;
	dst->m22 = 1;
	dst->m23 = 0;
	dst->m24 = mov->y;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = 1;
	dst->m34 = mov->z;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}

void attyr_scale(attyr_vec3 *scale, attyr_mat4x4 *dst)
{
	dst->m11 = scale->x;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m14 = 0;
	dst->m21 = 0;
	dst->m22 = scale->y;
	dst->m23 = 0;
	dst->m24 = 0;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = scale->z;
	dst->m34 = 0;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}

/*
* Camera helpers.
*
* Note that ATTYR does not implement frustrum culling, nor does it require depth
* values to be in [-1, 1]. So near and far planes are mostly pointless, and you
* should generally use 0 as near.
*/
void attyr_perspective(float fov, float aspect, float near, attyr_mat4x4 *dst)
{
	float s = 1/tan(fov/2);

	dst->m11 = s / aspect;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m14 = 0;
	dst->m21 = 0;
	dst->m22 = s;
	dst->m23 = 0;
	dst->m24 = 0;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = 1;
	dst->m34 = near;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = -1;
	dst->m44 = 0;
}

void attyr_orthographic(float fov, float aspect, float near, attyr_mat4x4 *dst)
{
	float s = 1/tan(fov/2);

	dst->m11 = s / aspect;
	dst->m12 = 0;
	dst->m13 = 0;
	dst->m14 = 0;
	dst->m21 = 0;
	dst->m22 = s;
	dst->m23 = 0;
	dst->m24 = 0;
	dst->m31 = 0;
	dst->m32 = 0;
	dst->m33 = 1;
	dst->m34 = near;
	dst->m41 = 0;
	dst->m42 = 0;
	dst->m43 = 0;
	dst->m44 = 1;
}
