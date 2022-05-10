#include "xalloc.h"

#include <stdlib.h>
#include <string.h>
#include <err.h>

void *xmalloc(size_t size)
{
    void *tmp = malloc(size);
    if (!tmp)
        errx(1, "Fail to allocate memory - xmalloc");
    return tmp;
}

void *xcalloc(size_t number, size_t size)
{
    void *tmp = calloc(number, size);
    if (!tmp)
        errx(1, "Fail to allocate memory - xcalloc");
    return tmp;
}

void *xrealloc(void *ptr, size_t size)
{
    void *tmp = realloc(ptr, size);
    if (!tmp)
        errx(1, "Fail to allocate memory - xrealloc");
    return tmp;
}

char *xstring(char *static_string)
{
    size_t len = strlen(static_string);

    char *new_char = xcalloc(1, len + 1);

    strcpy(new_char, static_string);
    return new_char;
}
