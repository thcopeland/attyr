#ifndef DARRAY_H
#define DARRAY_H

/*
 * A small dynamic array implementation.
 */

typedef struct {
    /*
     * data - a block of memory to store the contents of the array
     * elt  - the size in bytes of each element in the array
     * len  - the number of elements in the array
     * capacity - the number of elements that can fit in `data`
     */
    char *data;
    unsigned int elt, len, capacity;
} darray_t;

/*
 * Allocate and initialize a new empty dynamic array with an initial capacity
 * of `capacity`.
 */
darray_t *darray_init(unsigned int elt_size, unsigned int capacity);

/*
 * Free the given array (should have been allocated with `darray_init`).
 */
void darray_free(darray_t *ary);

/*
 * Return a pointer to the element at index `index`.
 */
void *darray_index(darray_t *ary, unsigned int index);

/*
 * Return a pointer to the last element. If the array is empty, return NULL.
 */
void *darray_last(darray_t *ary);

/*
 * Copy the given element to the given index.
 */
void darray_set(darray_t *ary, unsigned int index, void *elt);
/*
 * If the desired capacity exceeds the current capacity, allocate to the next
 * power of 2.
 */
void darray_resize(darray_t *ary, unsigned int desired_capacity);

/*
 * Append an element to the array.
 */
void darray_append(darray_t *ary, void *elt);

#endif
