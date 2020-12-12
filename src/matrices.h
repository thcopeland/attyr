#ifndef ATTYR_MATRICES_H
#define ATTYR_MATRICES_H

#ifndef ATTYR_MAT_INV_EPSILON
#define ATTYR_MAT_INV_EPSILON 0.000001
#endif

typedef struct {
	float x, y;
} attyr_vec2;

typedef struct {
	float x, y, z;
} attyr_vec3;

typedef struct {
	float x, y, z, w;
} attyr_vec4;

typedef struct {
	float m11, m12,
	      m21, m22;
} attyr_mat2x2;

typedef struct {
	float m11, m12, m13,
	      m21, m22, m23;
} attyr_mat2x3;

typedef struct {
	float m11, m12, m13, m14,
	      m21, m22, m23, m24;
} attyr_mat2x4;

typedef struct {
	float m11, m12,
	      m21, m22,
	      m31, m32;
} attyr_mat3x2;

typedef struct {
	float m11, m12, m13,
	      m21, m22, m23,
	      m31, m32, m33;
} attyr_mat3x3;

typedef struct {
	float m11, m12, m13, m14,
	      m21, m22, m23, m24,
	      m31, m32, m33, m34;
} attyr_mat3x4;

typedef struct {
	float m11, m12,
	      m21, m22,
	      m31, m32,
	      m41, m42;
} attyr_mat4x2;

typedef struct {
	float m11, m12, m13,
	      m21, m22, m23,
	      m31, m32, m33,
	      m41, m42, m43;
} attyr_mat4x3;

typedef struct {
	float m11, m12, m13, m14,
	      m21, m22, m23, m24,
	      m31, m32, m33, m34,
	      m41, m42, m43, m44;
} attyr_mat4x4;

/*
 * Initialize the entries in a vector
 */
void attyr_init_vec2(attyr_vec2 *v, float x, float y);
void attyr_init_vec3(attyr_vec3 *v, float x, float y, float z);
void attyr_init_vec4(attyr_vec4 *v, float x, float y, float z, float w);

/*
 * Initialize the entries in a matrix from column vectors.
 */
void attyr_init_mat2x2(attyr_mat2x2 *m, attyr_vec2 *col1, attyr_vec2 *col2);
void attyr_init_mat2x3(attyr_mat2x3 *m, attyr_vec2 *col1, attyr_vec2 *col2, attyr_vec2 *col3);
void attyr_init_mat2x4(attyr_mat2x4 *m, attyr_vec2 *col1, attyr_vec2 *col2, attyr_vec2 *col3, attyr_vec2 *col4);
void attyr_init_mat3x2(attyr_mat3x2 *m, attyr_vec3 *col1, attyr_vec3 *col2);
void attyr_init_mat3x3(attyr_mat3x3 *m, attyr_vec3 *col1, attyr_vec3 *col2, attyr_vec3 *col3);
void attyr_init_mat3x4(attyr_mat3x4 *m, attyr_vec3 *col1, attyr_vec3 *col2, attyr_vec3 *col3, attyr_vec3 *col4);
void attyr_init_mat4x2(attyr_mat4x2 *m, attyr_vec4 *col1, attyr_vec4 *col2);
void attyr_init_mat4x3(attyr_mat4x3 *m, attyr_vec4 *col1, attyr_vec4 *col2, attyr_vec4 *col3);
void attyr_init_mat4x4(attyr_mat4x4 *m, attyr_vec4 *col1, attyr_vec4 *col2, attyr_vec4 *col3, attyr_vec4 *col4);

/*
 * Copy the entries of the src vector to dst.
 */
void attyr_dup_vec2(attyr_vec2 *src, attyr_vec2 *dst);
void attyr_dup_vec3(attyr_vec3 *src, attyr_vec3 *dst);
void attyr_dup_vec4(attyr_vec4 *src, attyr_vec4 *dst);

/*
 * Copy the entries of the src matrix to dst.
 */
void attyr_dup_mat2x2(attyr_mat2x2 *src, attyr_mat2x2 *dst);
void attyr_dup_mat2x3(attyr_mat2x3 *src, attyr_mat2x3 *dst);
void attyr_dup_mat2x4(attyr_mat2x4 *src, attyr_mat2x4 *dst);
void attyr_dup_mat3x2(attyr_mat3x2 *src, attyr_mat3x2 *dst);
void attyr_dup_mat3x3(attyr_mat3x3 *src, attyr_mat3x3 *dst);
void attyr_dup_mat3x4(attyr_mat3x4 *src, attyr_mat3x4 *dst);
void attyr_dup_mat4x2(attyr_mat4x2 *src, attyr_mat4x2 *dst);
void attyr_dup_mat4x3(attyr_mat4x3 *src, attyr_mat4x3 *dst);
void attyr_dup_mat4x4(attyr_mat4x4 *src, attyr_mat4x4 *dst);

/*
 * Calculate the length of the vector.
 */
float attyr_len_vec2(attyr_vec2 *v);
float attyr_len_vec3(attyr_vec3 *v);
float attyr_len_vec4(attyr_vec4 *v);

/*
 * Multiply every entry in the vector by a scalar.
 */
void attyr_scale_vec2(attyr_vec2 *v, float s);
void attyr_scale_vec3(attyr_vec3 *v, float s);
void attyr_scale_vec4(attyr_vec4 *v, float s);

/*
 * Multiply every entry in the matrix by a scalar.
 */
void attyr_scale_mat2x2(attyr_mat2x2 *m, float s);
void attyr_scale_mat2x3(attyr_mat2x3 *m, float s);
void attyr_scale_mat2x4(attyr_mat2x4 *m, float s);
void attyr_scale_mat3x2(attyr_mat3x2 *m, float s);
void attyr_scale_mat3x3(attyr_mat3x3 *m, float s);
void attyr_scale_mat3x4(attyr_mat3x4 *m, float s);
void attyr_scale_mat4x2(attyr_mat4x2 *m, float s);
void attyr_scale_mat4x3(attyr_mat4x3 *m, float s);
void attyr_scale_mat4x4(attyr_mat4x4 *m, float s);

/*
 * Add the first two vectors and place the result in the third.
 */
void attyr_add_vec2(attyr_vec2 *a, attyr_vec2 *b, attyr_vec2 *c);
void attyr_add_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c);
void attyr_add_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c);

/*
 * Add the first two matrices and place the result in the third.
 */
void attyr_add_mat2x2(attyr_mat2x2 *a, attyr_mat2x2 *b, attyr_mat2x2 *c);
void attyr_add_mat2x3(attyr_mat2x3 *a, attyr_mat2x3 *b, attyr_mat2x3 *c);
void attyr_add_mat2x4(attyr_mat2x4 *a, attyr_mat2x4 *b, attyr_mat2x4 *c);
void attyr_add_mat3x2(attyr_mat3x2 *a, attyr_mat3x2 *b, attyr_mat3x2 *c);
void attyr_add_mat3x3(attyr_mat3x3 *a, attyr_mat3x3 *b, attyr_mat3x3 *c);
void attyr_add_mat3x4(attyr_mat3x4 *a, attyr_mat3x4 *b, attyr_mat3x4 *c);
void attyr_add_mat4x2(attyr_mat4x2 *a, attyr_mat4x2 *b, attyr_mat4x2 *c);
void attyr_add_mat4x3(attyr_mat4x3 *a, attyr_mat4x3 *b, attyr_mat4x3 *c);
void attyr_add_mat4x4(attyr_mat4x4 *a, attyr_mat4x4 *b, attyr_mat4x4 *c);

/*
 * Subtract the second vector from the first and place the result in the third.
 */
void attyr_sub_vec2(attyr_vec2 *a, attyr_vec2 *b, attyr_vec2 *c);
void attyr_sub_vec3(attyr_vec3 *a, attyr_vec3 *b, attyr_vec3 *c);
void attyr_sub_vec4(attyr_vec4 *a, attyr_vec4 *b, attyr_vec4 *c);

/*
* Subtract the second matrix from the first and place the result in the third.
 */
void attyr_sub_mat2x2(attyr_mat2x2 *a, attyr_mat2x2 *b, attyr_mat2x2 *c);
void attyr_sub_mat2x3(attyr_mat2x3 *a, attyr_mat2x3 *b, attyr_mat2x3 *c);
void attyr_sub_mat2x4(attyr_mat2x4 *a, attyr_mat2x4 *b, attyr_mat2x4 *c);
void attyr_sub_mat3x2(attyr_mat3x2 *a, attyr_mat3x2 *b, attyr_mat3x2 *c);
void attyr_sub_mat3x3(attyr_mat3x3 *a, attyr_mat3x3 *b, attyr_mat3x3 *c);
void attyr_sub_mat3x4(attyr_mat3x4 *a, attyr_mat3x4 *b, attyr_mat3x4 *c);
void attyr_sub_mat4x2(attyr_mat4x2 *a, attyr_mat4x2 *b, attyr_mat4x2 *c);
void attyr_sub_mat4x3(attyr_mat4x3 *a, attyr_mat4x3 *b, attyr_mat4x3 *c);
void attyr_sub_mat4x4(attyr_mat4x4 *a, attyr_mat4x4 *b, attyr_mat4x4 *c);

/*
 * Compute the vector dot product of two vectors.
 */
float attyr_dot_vec2(attyr_vec2 *a, attyr_vec2 *b);
float attyr_dot_vec3(attyr_vec3 *a, attyr_vec3 *b);
float attyr_dot_vec4(attyr_vec4 *a, attyr_vec4 *b);

/*
 * Compute the product of two matrices, or a matrix and a vector, and place
 * the result in a third. The destination can be a factor as well.
 */
void attyr_mult_mat2x2_vec2(attyr_mat2x2 *m, attyr_vec2 *v, attyr_vec2 *dst);
void attyr_mult_mat2x3_vec3(attyr_mat2x3 *m, attyr_vec3 *v, attyr_vec2 *dst);
void attyr_mult_mat2x4_vec4(attyr_mat2x4 *m, attyr_vec4 *v, attyr_vec2 *dst);
void attyr_mult_mat3x2_vec2(attyr_mat3x2 *m, attyr_vec2 *v, attyr_vec3 *dst);
void attyr_mult_mat3x3_vec3(attyr_mat3x3 *m, attyr_vec3 *v, attyr_vec3 *dst);
void attyr_mult_mat3x4_vec4(attyr_mat3x4 *m, attyr_vec4 *v, attyr_vec3 *dst);
void attyr_mult_mat4x2_vec2(attyr_mat4x2 *m, attyr_vec2 *v, attyr_vec4 *dst);
void attyr_mult_mat4x3_vec3(attyr_mat4x3 *m, attyr_vec3 *v, attyr_vec4 *dst);
void attyr_mult_mat4x4_vec4(attyr_mat4x4 *m, attyr_vec4 *v, attyr_vec4 *dst);
void attyr_mult_mat2x2_2x2(attyr_mat2x2 *a, attyr_mat2x2 *b, attyr_mat2x2 *dst);
void attyr_mult_mat2x2_2x3(attyr_mat2x2 *a, attyr_mat2x3 *b, attyr_mat2x3 *dst);
void attyr_mult_mat2x2_2x4(attyr_mat2x2 *a, attyr_mat2x4 *b, attyr_mat2x4 *dst);
void attyr_mult_mat2x3_3x2(attyr_mat2x3 *a, attyr_mat3x2 *b, attyr_mat2x2 *dst);
void attyr_mult_mat2x3_3x3(attyr_mat2x3 *a, attyr_mat3x3 *b, attyr_mat2x3 *dst);
void attyr_mult_mat2x3_3x4(attyr_mat2x3 *a, attyr_mat3x4 *b, attyr_mat2x4 *dst);
void attyr_mult_mat2x4_4x2(attyr_mat2x4 *a, attyr_mat4x2 *b, attyr_mat2x2 *dst);
void attyr_mult_mat2x4_4x3(attyr_mat2x4 *a, attyr_mat4x3 *b, attyr_mat2x3 *dst);
void attyr_mult_mat2x4_4x4(attyr_mat2x4 *a, attyr_mat4x4 *b, attyr_mat2x4 *dst);
void attyr_mult_mat3x2_2x2(attyr_mat3x2 *a, attyr_mat2x2 *b, attyr_mat3x2 *dst);
void attyr_mult_mat3x2_2x3(attyr_mat3x2 *a, attyr_mat2x3 *b, attyr_mat3x3 *dst);
void attyr_mult_mat3x2_2x4(attyr_mat3x2 *a, attyr_mat2x4 *b, attyr_mat3x4 *dst);
void attyr_mult_mat3x3_3x2(attyr_mat3x3 *a, attyr_mat3x2 *b, attyr_mat3x2 *dst);
void attyr_mult_mat3x3_3x3(attyr_mat3x3 *a, attyr_mat3x3 *b, attyr_mat3x3 *dst);
void attyr_mult_mat3x3_3x4(attyr_mat3x3 *a, attyr_mat3x4 *b, attyr_mat3x4 *dst);
void attyr_mult_mat3x4_4x2(attyr_mat3x4 *a, attyr_mat4x2 *b, attyr_mat3x2 *dst);
void attyr_mult_mat3x4_4x3(attyr_mat3x4 *a, attyr_mat4x3 *b, attyr_mat3x3 *dst);
void attyr_mult_mat3x4_4x4(attyr_mat3x4 *a, attyr_mat4x4 *b, attyr_mat3x4 *dst);
void attyr_mult_mat4x2_2x2(attyr_mat4x2 *a, attyr_mat2x2 *b, attyr_mat4x2 *dst);
void attyr_mult_mat4x2_2x3(attyr_mat4x2 *a, attyr_mat2x3 *b, attyr_mat4x3 *dst);
void attyr_mult_mat4x2_2x4(attyr_mat4x2 *a, attyr_mat2x4 *b, attyr_mat4x4 *dst);
void attyr_mult_mat4x3_3x2(attyr_mat4x3 *a, attyr_mat3x2 *b, attyr_mat4x2 *dst);
void attyr_mult_mat4x3_3x3(attyr_mat4x3 *a, attyr_mat3x3 *b, attyr_mat4x3 *dst);
void attyr_mult_mat4x3_3x4(attyr_mat4x3 *a, attyr_mat3x4 *b, attyr_mat4x4 *dst);
void attyr_mult_mat4x4_4x2(attyr_mat4x4 *a, attyr_mat4x2 *b, attyr_mat4x2 *dst);
void attyr_mult_mat4x4_4x3(attyr_mat4x4 *a, attyr_mat4x3 *b, attyr_mat4x3 *dst);
void attyr_mult_mat4x4_4x4(attyr_mat4x4 *a, attyr_mat4x4 *b, attyr_mat4x4 *dst);

/*
 * Invert the given 3x3 matrix, if possible, and return the determinant. If the
 * determinant is sufficiently small, returns 0.
 */
float attyr_invert_mat3x3(attyr_mat3x3 *m);

#endif
