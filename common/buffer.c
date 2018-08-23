#include <stdlib.h>
#include <string.h>

#include "buffer.h"

struct _buffer
{
    ssize_t capacity;
    ssize_t length;
    char *data;
};


buffer_t* buffer_new(const ssize_t capacity)
{
    buffer_t* buffer = (buffer_t*)calloc(1,sizeof(buffer_t) + capacity);
    if(!buffer) {
        return NULL;
    }

    buffer->capacity = capacity;
    buffer->length = 0;
    buffer->data = (char*)buffer + sizeof(buffer_t);

    return buffer;
}

ssize_t buffer_append(buffer_t *buffer, const char *data, const ssize_t len)
{
    ssize_t left = buffer->capacity - buffer->length;
    ssize_t ncopy = (left >= len) ? len : left;
    memcpy(buffer->data +  buffer->length, data, ncopy);
    buffer->length += ncopy;
    return ncopy;
}

ssize_t buffer_remove(buffer_t *buffer,const ssize_t start, const ssize_t len)
{
    if(start < 0 || len <= 0 || start >= buffer->length) {
        return -1;
    }

    int nremove = (start + len) > buffer->length ? (buffer->length - start) : len;
    if((nremove + start) == (buffer->length)) {
        memset(buffer->data + start,0,nremove);
    } else {
        memmove(buffer->data + start, buffer->data + start + nremove, buffer->length - start - nremove);
        // clean dirty data, not really need
        // just for debug
        //memset(buffer->data + buffer->length - nremove, 0, nremove);
    }

    buffer->length -= nremove;

    return nremove;
}

ssize_t buffer_pop(buffer_t *buffer,const ssize_t len)
{
    if(len <= 0) {
        return 0;
    }
    ssize_t nremove = (len > buffer->length) ? buffer->length : len;
    if(nremove == buffer->length) {
        memset(buffer->data,0,nremove);
    } else {
        memmove(buffer->data, buffer->data + nremove, buffer->length - nremove);
    }
    buffer->length -= nremove;
    return nremove;
}

ssize_t buffer_copy(const buffer_t *buffer, char* dst, const ssize_t dst_len, const ssize_t n)
{
    ssize_t ncopy = (dst_len > n) ? n : dst_len;
    memcpy(dst, buffer->data, ncopy);
    return ncopy;
}

const char* buffer_data(const buffer_t *buffer)
{
    return buffer->data;
}

const ssize_t buffer_data_length(const buffer_t *buffer)
{
    return buffer->length;
}

void buffer_reset(buffer_t *buffer)
{
    memset(buffer->data,0,buffer->length);
    buffer->length = 0;
}

void buffer_free(buffer_t *buffer)
{
    free(buffer);
    buffer = NULL;
}
