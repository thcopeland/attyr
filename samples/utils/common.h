#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

/*
 * Print a message and abort.
 */
#define die(...) do {                                                          \
        fprintf(stderr, __VA_ARGS__);                                          \
        exit(1);                                                               \
    } while (0)

/*
 * Allocate `size` bytes of memory or abort trying.
 */
void *xmalloc(size_t size);

/*
 * Reallocate `size` bytes of memory at `ptr` or abort trying.
 */
void *xrealloc(void *ptr, size_t size);
/*
 * Read the next line of the file. If the buffer is insufficiently long, the
 * excess bytes are not stored.
 */
int readline(FILE *f, char *buff, int size);

#endif
