#ifndef COMMON_STR_H
#define COMMON_STR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    size_t length; /* length of string */
    unsigned char* s; /* string data */
} str_t;

extern str_t* str_new(size_t size);
extern void str_set(str_t *str, const char *s, const size_t size);
extern void str_free(str_t **str);

#ifdef __cplusplus
}
#endif

#endif
