#include "transform.h"

/*
 * REWRITE! this is the OpenGL perspective matrix. we should use a different one
 * for the Olano-Greer algorithm
 */
void perspective_transform(mat4 *matrix,
                           float left,
                           float right,
                           float bottom,
                           float top,
                           float near,
                           float far)
{
    float width = right-left, height = top-bottom, depth = far-near;

    matrix->m11 = 2*near/width;
    matrix->m12 = 0;
    matrix->m13 = (right+left)/width;
    matrix->m14 = 0;

    matrix->m21 = 0;
    matrix->m22 = 2*near/height;
    matrix->m23 = (top+bottom)/height;
    matrix->m24 = 0;

    matrix->m31 = 0;
    matrix->m32 = 0;
    matrix->m33 = -(near+far)/depth;
    matrix->m34 = -2*near*far/depth;

    matrix->m41 = 0;
    matrix->m42 = 0;
    matrix->m43 = -1;
    matrix->m44 = 0;
}
