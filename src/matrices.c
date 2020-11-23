#include "matrices.h"
#include <math.h> /* fabs */

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

void attyr_dup_vec3(attyr_vec3 *src, attyr_vec3 *dst)
{
    *dst = *src;
}

void attyr_dup_vec4(attyr_vec4 *src, attyr_vec4 *dst)
{
    *dst = *src;
}

void attyr_dup_mat3(attyr_mat3 *src, attyr_mat3 *dst)
{
    *dst = *src;
}

void attyr_dup_mat4(attyr_mat4 *src, attyr_mat4 *dst)
{
    *dst = *src;
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

void attyr_scale_mat3(attyr_mat3 *m, float s)
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

void attyr_scale_mat4(attyr_mat4 *m, float s)
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

void attyr_add_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c)
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

void attyr_add_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c)
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

void attyr_sub_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c)
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

void attyr_sub_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c)
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

void attyr_had_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c)
{
    c->x = a->x * b->x;
    c->y = a->y * b->y;
    c->z = a->z * b->z;
}

void attyr_had_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c)
{
    c->x = a->x * b->x;
    c->y = a->y * b->y;
    c->z = a->z * b->z;
    c->w = a->w * b->w;
}

void attyr_had_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c)
{
    c->m11 = a->m11 * b->m11;
    c->m12 = a->m12 * b->m12;
    c->m13 = a->m13 * b->m13;
    c->m21 = a->m21 * b->m21;
    c->m22 = a->m22 * b->m22;
    c->m23 = a->m23 * b->m23;
    c->m31 = a->m31 * b->m31;
    c->m32 = a->m32 * b->m32;
    c->m33 = a->m33 * b->m33;
}

void attyr_had_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c)
{
    c->m11 = a->m11 * b->m11;
    c->m12 = a->m12 * b->m12;
    c->m13 = a->m13 * b->m13;
    c->m14 = a->m14 * b->m14;
    c->m21 = a->m21 * b->m21;
    c->m22 = a->m22 * b->m22;
    c->m23 = a->m23 * b->m23;
    c->m24 = a->m24 * b->m24;
    c->m31 = a->m31 * b->m31;
    c->m32 = a->m32 * b->m32;
    c->m33 = a->m33 * b->m33;
    c->m34 = a->m34 * b->m34;
    c->m41 = a->m41 * b->m41;
    c->m42 = a->m42 * b->m42;
    c->m43 = a->m43 * b->m43;
    c->m44 = a->m44 * b->m44;
}

float attyr_dot_vec3(attyr_vec3 *a, attyr_vec3 *b)
{
    return a->x*b->x + a->y*b->y + a->z*b->z;
}

float attyr_dot_vec4(attyr_vec4 *a, attyr_vec4 *b)
{
    return a->x*b->x + a->y*b->y + a->z*b->z + a->w*b->w;
}

void attyr_dot_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c)
{
    c->m11 = a->m11*b->m11 + a->m12*b->m21 + a->m13*b->m31;
    c->m12 = a->m11*b->m12 + a->m12*b->m22 + a->m13*b->m32;
    c->m13 = a->m11*b->m13 + a->m12*b->m23 + a->m13*b->m33;
    c->m21 = a->m21*b->m11 + a->m22*b->m21 + a->m23*b->m31;
    c->m22 = a->m21*b->m12 + a->m22*b->m22 + a->m23*b->m32;
    c->m23 = a->m21*b->m13 + a->m22*b->m23 + a->m23*b->m33;
    c->m31 = a->m31*b->m11 + a->m32*b->m21 + a->m33*b->m31;
    c->m32 = a->m31*b->m12 + a->m32*b->m22 + a->m33*b->m32;
    c->m33 = a->m31*b->m13 + a->m32*b->m23 + a->m33*b->m33;
}

void attyr_dot_mat3vec3(attyr_mat3 *m, attyr_vec3 *v, attyr_vec3 *c)
{
    c->x = m->m11*v->x + m->m12*v->y + m->m13*v->z;
    c->y = m->m21*v->x + m->m22*v->y + m->m23*v->z;
    c->z = m->m31*v->x + m->m32*v->y + m->m33*v->z;
}

void attyr_dot_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c)
{
    c->m11 = a->m11*b->m11 + a->m12*b->m21 + a->m13*b->m31 + a->m14*b->m41;
    c->m12 = a->m11*b->m12 + a->m12*b->m22 + a->m13*b->m32 + a->m14*b->m42;
    c->m13 = a->m11*b->m13 + a->m12*b->m23 + a->m13*b->m33 + a->m14*b->m43;
    c->m14 = a->m11*b->m14 + a->m12*b->m24 + a->m13*b->m34 + a->m14*b->m44;
    c->m21 = a->m21*b->m11 + a->m22*b->m21 + a->m23*b->m31 + a->m24*b->m41;
    c->m22 = a->m21*b->m12 + a->m22*b->m22 + a->m23*b->m32 + a->m24*b->m42;
    c->m23 = a->m21*b->m13 + a->m22*b->m23 + a->m23*b->m33 + a->m24*b->m43;
    c->m24 = a->m21*b->m14 + a->m22*b->m24 + a->m23*b->m34 + a->m24*b->m44;
    c->m31 = a->m31*b->m11 + a->m32*b->m21 + a->m33*b->m31 + a->m34*b->m41;
    c->m32 = a->m31*b->m12 + a->m32*b->m22 + a->m33*b->m32 + a->m34*b->m42;
    c->m33 = a->m31*b->m13 + a->m32*b->m23 + a->m33*b->m33 + a->m34*b->m43;
    c->m34 = a->m31*b->m14 + a->m32*b->m24 + a->m33*b->m34 + a->m34*b->m44;
    c->m41 = a->m41*b->m11 + a->m42*b->m21 + a->m43*b->m31 + a->m44*b->m41;
    c->m42 = a->m41*b->m12 + a->m42*b->m22 + a->m43*b->m32 + a->m44*b->m42;
    c->m43 = a->m41*b->m13 + a->m42*b->m23 + a->m43*b->m33 + a->m44*b->m43;
    c->m44 = a->m41*b->m14 + a->m42*b->m24 + a->m43*b->m34 + a->m44*b->m44;
}

void attyr_dot_mat4vec4(attyr_mat4 *m, attyr_vec4 *v, attyr_vec4 *c)
{
    c->x = m->m11*v->x + m->m12*v->y + m->m13*v->z + m->m14*v->w;
    c->y = m->m21*v->x + m->m22*v->y + m->m23*v->z + m->m24*v->w;
    c->z = m->m31*v->x + m->m32*v->y + m->m33*v->z + m->m34*v->w;
    c->w = m->m41*v->x + m->m42*v->y + m->m43*v->z + m->m44*v->w;
}

float attyr_invert_mat3(attyr_mat3 *m)
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
