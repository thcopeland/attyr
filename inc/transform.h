#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "matrices.h"

void perspective_transform(mat4 *matrix,
                           float left,
                           float right,
                           float bottom,
                           float top,
                           float near,
                           float far);

#endif
