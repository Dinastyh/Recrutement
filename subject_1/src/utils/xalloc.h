#ifndef XALLOC_h
#define XALLOC_h

#include <stddef.h>

void *xmalloc(size_t size);
void *xcalloc(size_t number, size_t size);
void *xrealloc(void *ptr, size_t size);
char *xstring(char *static_string);

#endif