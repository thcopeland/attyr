#include "transform.h"

void perspective_transform(mat4 *matrix,
                           float left,
                           float right,
                           float bottom,
                           float top,
                           float near,
                           float far)
{
    float width = right-left, height = top-bottom, depth = far-near;

    matrix->val[0] = 2*near/width;
    matrix->val[1] = 0;
    matrix->val[2] = (right+left)/width;
    matrix->val[3] = 0;

    matrix->val[4] = 0;
    matrix->val[5] = 2*near/height;
    matrix->val[6] = (top+bottom)/height;
    matrix->val[7] = 0;

    matrix->val[8] = 0;
    matrix->val[9] = 0;
    matrix->val[10] = -(near+far)/depth;
    matrix->val[11] = -2*near*far/depth;

    matrix->val[12] = 0;
    matrix->val[13] = 0;
    matrix->val[14] = -1;
    matrix->val[15] = 0;
}
