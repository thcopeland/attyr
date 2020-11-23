#ifndef ATTYR_MATRICES_H
#define ATTYR_MATRICES_H

#ifndef ATTYR_MAT_INV_EPSILON
#define ATTYR_MAT_INV_EPSILON 0.000001
#endif

typedef struct {
    float x, y, z;
} attyr_vec3;

typedef struct {
    float x, y, z, w;
} attyr_vec4;

typedef struct {
    float m11, m12, m13,
          m21, m22, m23,
          m31, m32, m33;
} attyr_mat3;

typedef struct {
    float m11, m12, m13, m14,
          m21, m22, m23, m24,
          m31, m32, m33, m34,
          m41, m42, m43, m44;
} attyr_mat4;

/*
 * Initialize the entries in a vector.
 */
void attyr_init_vec3(attyr_vec3 *v, float x, float y, float z);
void attyr_init_vec4(attyr_vec4 *v, float x, float y, float z, float w);

/*
 * Copy the contents of src into dst.
 */
void attyr_dup_vec3(attyr_vec3 *src, attyr_vec3 *dst);
void attyr_dup_vec4(attyr_vec4 *src, attyr_vec4 *dst);
void attyr_dup_mat3(attyr_mat3 *src, attyr_mat3 *dst);
void attyr_dup_mat4(attyr_mat4 *src, attyr_mat4 *dst);

/*
 * Multiply each element of a by s, a scalar.
 */
void attyr_scale_vec3(attyr_vec3 *a, float s);
void attyr_scale_vec4(attyr_vec4 *a, float s);
void attyr_scale_mat3(attyr_mat3 *a, float s);
void attyr_scale_mat4(attyr_mat4 *a, float s);

/*
 * Add a and b and place the result in c.
 */
void attyr_add_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c);
void attyr_add_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c);
void attyr_add_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c);
void attyr_add_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c);

/*
 * Subtract b from a and place the result in c.
 */
void attyr_sub_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c);
void attyr_sub_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c);
void attyr_sub_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c);
void attyr_sub_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c);

/*
 * Calculate the Hadamard product of a and b and place the result in c.
 */
void attyr_had_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c);
void attyr_had_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c);
void attyr_had_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c);
void attyr_had_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c);

/*
 * Calculate the vector dot product of a and b.
 */
float attyr_dot_vec3(attyr_vec3 *a, attyr_vec3 *b);
float attyr_dot_vec4(attyr_vec4 *a, attyr_vec4 *b);

/*
 * Calculate the matrix product of a and b and place the result in c.
 */
void attyr_dot_mat3(attyr_mat3 *a, attyr_mat3 *b, attyr_mat3 *c);
void attyr_dot_mat4(attyr_mat4 *a, attyr_mat4 *b, attyr_mat4 *c);
void attyr_dot_mat3vec3(attyr_mat3 *a, attyr_vec3 *b, attyr_vec3 *c);
void attyr_dot_mat4vec4(attyr_mat4 *a, attyr_vec4 *b, attyr_vec4 *c);

/*
 * Invert the given 3x3 matrix, if possible, and return the determinant.
 */
float attyr_invert_mat3(attyr_mat3 *m);

#endif
