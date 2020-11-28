#include "darray.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "common.h"

darray_t *darray_init(unsigned int elt_size, unsigned int capacity)
{
    darray_t *ary = xmalloc(sizeof(darray_t));

    ary->data = xmalloc(elt_size * capacity);
    ary->elt = elt_size;
    ary->len = 0;
    ary->capacity = capacity;

    return ary;
}

void darray_free(darray_t *ary)
{
    free(ary->data);
    free(ary);
}

void *darray_index(darray_t *ary, unsigned int index)
{
    return (void *) (ary->data + index * ary->elt);
}

void *darray_last(darray_t *ary)
{
    if (ary->len == 0) return NULL;

    return darray_index(ary, ary->len-1);
}

void darray_set(darray_t *ary, unsigned int index, void *elt)
{
    memcpy(darray_index(ary, index), elt, ary->elt);
}

void darray_resize(darray_t *ary, unsigned int desired_capacity)
{
    if (desired_capacity > ary->capacity) {
        unsigned int new_capacity = 1;

        if (desired_capacity > 0) {
            new_capacity <<= (unsigned int) ceil(log2(desired_capacity));
        }

        ary->data = xrealloc(ary->data, ary->elt*new_capacity);
        ary->capacity = new_capacity;
    }
}

void darray_append(darray_t *ary, void *elt)
{
    darray_resize(ary, ary->len+1);
    darray_set(ary, ary->len, elt);
    ary->len++;
}
