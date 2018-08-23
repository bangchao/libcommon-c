#include <stdlib.h>
#include <string.h>

#include "str.h"

str_t* str_new(size_t size)
{
    str_t *str = (str_t*)malloc(sizeof(str_t) + size + 1);
    if(!str) {
        return NULL;
    }

    memset(str, 0, sizeof(str_t) + size + 1);
    str->s = (unsigned char*)str + sizeof(str_t);
    return str;
}

void str_set(str_t *str, const char *s, const size_t size)
{
    memcpy(str->s, s, size);
    str->length = size;
}

void str_free(str_t **str)
{
    if(!str || !(*str)) {
        return;
    }

    free(*str);
    *str = NULL;
}
