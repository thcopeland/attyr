#ifndef MATRICES_H
#define MATRICES_H

#ifndef MAT_INV_EPSILON
#define MAT_INV_EPSILON 0.000001
#endif

typedef struct {
    float x, y, z;
} vec3;

typedef struct {
    float x, y, z, w;
} vec4;

typedef struct {
    float m11, m12, m13,
          m21, m22, m23,
          m31, m32, m33;
} mat3;

typedef struct {
    float m11, m12, m13, m14,
          m21, m22, m23, m24,
          m31, m32, m33, m34,
          m41, m42, m43, m44;
} mat4;

/*
 * Initialize the entries in a vector.
 */
void init_vec3(vec3 *v, float x, float y, float z);
void init_vec4(vec4 *v, float x, float y, float z, float w);

/*
 * Copy the contents of src into dst.
 */
void dup_vec3(vec3 *src, vec3 *dst);
void dup_vec4(vec4 *src, vec4 *dst);
void dup_mat3(mat3 *src, mat3 *dst);
void dup_mat4(mat4 *src, mat4 *dst);

/*
 * Multiply each element of a by s, a scalar.
 */
void scale_vec3(vec3 *a, float s);
void scale_vec4(vec4 *a, float s);
void scale_mat3(mat3 *a, float s);
void scale_mat4(mat4 *a, float s);

/*
 * Add a and b and place the result in c.
 */
void add_vec3(vec3 *a, vec3 *b, vec3 *c);
void add_vec4(vec4 *a, vec4 *b, vec4 *c);
void add_mat3(mat3 *a, mat3 *b, mat3 *c);
void add_mat4(mat4 *a, mat4 *b, mat4 *c);

/*
 * Subtract b from a and place the result in c.
 */
void sub_vec3(vec3 *a, vec3 *b, vec3 *c);
void sub_vec4(vec4 *a, vec4 *b, vec4 *c);
void sub_mat3(mat3 *a, mat3 *b, mat3 *c);
void sub_mat4(mat4 *a, mat4 *b, mat4 *c);

/*
 * Calculate the Hadamard product of a and b and place the result in c.
 */
void had_vec3(vec3 *a, vec3 *b, vec3 *c);
void had_vec4(vec4 *a, vec4 *b, vec4 *c);
void had_mat3(mat3 *a, mat3 *b, mat3 *c);
void had_mat4(mat4 *a, mat4 *b, mat4 *c);

/*
 * Calculate the vector dot product of a and b.
 */
float dot_vec3(vec3 *a, vec3 *b);
float dot_vec4(vec4 *a, vec4 *b);

/*
 * Calculate the matrix product of a and b and place the result in c.
 */
void dot_mat3(mat3 *a, mat3 *b, mat3 *c);
void dot_mat4(mat4 *a, mat4 *b, mat4 *c);
void dot_mat3vec3(mat3 *a, vec3 *b, vec3 *c);
void dot_mat4vec4(mat4 *a, vec4 *b, vec4 *c);

/*
 * Invert the given 3x3 matrix, if possible, and return the determinant.
 */
float invert_mat3(mat3 *m);

#endif
