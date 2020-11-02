#ifndef MATRICES_H
#define MATRICES_H

typedef struct {
    float val[2];
} vec2;

typedef struct {
    float val[3];
} vec3;

typedef struct {
    float val[4];
} vec4;

typedef struct {
    float val[4];
} mat2;

typedef struct {
    float val[9];
} mat3;

typedef struct {
    float val[16];
} mat4;

/*
 * Copy the contents of src into dst.
 */
void dup_vec2(vec2 *src, vec2 *dst);
void dup_vec3(vec3 *src, vec3 *dst);
void dup_vec4(vec4 *src, vec4 *dst);
void dup_mat2(mat2 *src, mat2 *dst);
void dup_mat3(mat3 *src, mat3 *dst);
void dup_mat4(mat4 *src, mat4 *dst);

/*
 * Multiply each element of a by s, a scalar.
 */
void scale_vec2(vec2 *v, float s);
void scale_vec3(vec3 *a, float s);
void scale_vec4(vec4 *a, float s);
void scale_mat2(mat2 *a, float s);
void scale_mat3(mat3 *a, float s);
void scale_mat4(mat4 *a, float s);

/*
 * Add a and b and place the result in c.
 */
void add_vec2(vec2 *a, vec2 *b, vec2 *c);
void add_vec3(vec3 *a, vec3 *b, vec3 *c);
void add_vec4(vec4 *a, vec4 *b, vec4 *c);
void add_mat2(mat2 *a, mat2 *b, mat2 *c);
void add_mat3(mat3 *a, mat3 *b, mat3 *c);
void add_mat4(mat4 *a, mat4 *b, mat4 *c);

/*
 * Subtract b from a and place the result in c.
 */
void sub_vec2(vec2 *a, vec2 *b, vec2 *c);
void sub_vec3(vec3 *a, vec3 *b, vec3 *c);
void sub_vec4(vec4 *a, vec4 *b, vec4 *c);
void sub_mat2(mat2 *a, mat2 *b, mat2 *c);
void sub_mat3(mat3 *a, mat3 *b, mat3 *c);
void sub_mat4(mat4 *a, mat4 *b, mat4 *c);

/*
 * Calculate the Hadamard product of a and b and place the result in c.
 */
void had_vec2(vec2 *a, vec2 *b, vec2 *c);
void had_vec3(vec3 *a, vec3 *b, vec3 *c);
void had_vec4(vec4 *a, vec4 *b, vec4 *c);
void had_mat2(mat2 *a, mat2 *b, mat2 *c);
void had_mat3(mat3 *a, mat3 *b, mat3 *c);
void had_mat4(mat4 *a, mat4 *b, mat4 *c);

/*
 * Calculate the vector dot product of a and b.
 */
float dot_vec2(vec2 *a, vec2 *b);
float dot_vec3(vec3 *a, vec3 *b);
float dot_vec4(vec4 *a, vec4 *b);

/*
 * Calculate the matrix product of a and b and place the result in c.
 */
void dot_mat2(mat2 *a, mat2 *b, mat2 *c);
void dot_mat3(mat3 *a, mat3 *b, mat3 *c);
void dot_mat4(mat4 *a, mat4 *b, mat4 *c);
void dot_mat2vec2(mat2 *a, vec2 *b, vec2 *c);
void dot_mat3vec3(mat3 *a, vec3 *b, vec3 *c);
void dot_mat4vec4(mat4 *a, vec4 *b, vec4 *c);

#endif
