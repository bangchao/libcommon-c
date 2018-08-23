#include <stdlib.h>
#include <string.h>

#include "block.h"


block_t* block_new(const ssize_t capacity)
{
    block_t* block = (block_t*)calloc(1,sizeof(block_t) + capacity);
    if(!block) {
        return NULL;
    }

    block->capacity = capacity;
    block->length = 0;
    block->data = (char*)block + sizeof(block_t);

    return block;
}

int block_append(block_t *block, const char *data, const ssize_t len)
{
    ssize_t left = block->capacity - block->length;
    ssize_t ncopy = (left >= len) ? len : left;
    memcpy(block->data +  block->length, data, ncopy);
    block->length += ncopy;
    return ncopy;
}

int block_remove(block_t *block,const ssize_t start, const ssize_t len)
{
    if(start < 0 || len <= 0 || start >= block->length) {
        return -1;
    }

    int nremove = (start + len) > block->length ? (block->length - start) : len;
    if((nremove + start) == (block->length)) {
        memset(block->data + start,0,nremove);
    } else {
        memmove(block->data + start, block->data + start + nremove, block->length - start - nremove);
        // clean dirty data, not really need
        // just for debug
        //memset(block->data + block->length - nremove, 0, nremove);
    }

    block->length -= nremove;

    return nremove;
}

void block_reset(block_t *block)
{
    memset(block->data,0,block->length);
    block->length = 0;
}

void block_free(block_t *block)
{
    free(block);
    block = NULL;
}
