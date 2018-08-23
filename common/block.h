/**
 * Written by DuanBangChao
 * 主要用于socket之类的需要做数据缓存
 *
 */
#ifndef COMMON_BLOCK_H
#define COMMON_BLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _block
{
    ssize_t capacity;
    ssize_t length;
    char *data;
} block_t;

/**
 * 申请可以存放capacity的block,成功返回地址，失败返回NULL
 */
extern block_t* block_new(const ssize_t capacity);

/**
 * 存放数据，返回实际存放的数据的长度
 */
extern int block_append(block_t *block, const char *data, const ssize_t len);

/**
 * 移除指定数据,返回实际移除数据数目
 * -1表示参数错误
 */
extern int block_remove(block_t *block,const ssize_t start, const ssize_t len);

/**
 * 清空block
 */
extern void block_reset(block_t *block);

/**
 * 释放block
 */
extern void block_free(block_t *block);

#ifdef __cplusplus
}
#endif

#endif
