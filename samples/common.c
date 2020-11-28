#include "common.h"

#include <stdlib.h>

void *xmalloc(size_t size)
{
    void *mem = malloc(size);
    if (!mem) die("(darray) Unable to allocate memory\n");
    return mem;
}

void *xrealloc(void *ptr, size_t size)
{
    void *mem = realloc(ptr, size);
    if (!mem) die("(darray) Unable to reallocate memory\n");
    return mem;
}

int readline(FILE *f, char *buff, int size)
{
    int i = 0, c;

    while ((c=getc(f)) != EOF && c != '\n') {
        if (i < size-1) buff[i] = c;
        ++i;
    }
    buff[i] = '\0';

    return i;
}
