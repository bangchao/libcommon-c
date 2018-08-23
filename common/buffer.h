/**
 * Written by DuanBangChao
 * 主要用于socket之类的需要做数据缓存
 *
 */
#ifndef COMMON_BUFFER_H
#define COMMON_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _buffer buffer_t;

/**
 * 申请可以存放capacity的buffer,成功返回地址，失败返回NULL
 */
extern buffer_t* buffer_new(const ssize_t capacity);

/**
 * 存放数据，返回实际存放的数据的长度
 */
extern ssize_t buffer_append(buffer_t *buffer, const char *data, const ssize_t len);

/**
 * 移除指定数据,返回实际移除数据数目
 * -1表示参数错误
 */
extern ssize_t buffer_remove(buffer_t *buffer,const ssize_t start, const ssize_t len);

/**
 * 移除buffer前面n个字节
 */
extern ssize_t buffer_pop(buffer_t *buffer,const ssize_t len);

/**
 * 从buffer中复制数据
 * dst -- 目标
 * dst_len: 目标长度
 * n -- 需要复制的字节数
 *
 */
extern ssize_t buffer_copy(const buffer_t *buffer, char* dst, const ssize_t dst_len, const ssize_t n);

/**
 * 返回buffer中的原始数据
 */
extern const char* buffer_data(const buffer_t *buffer);

/**
 * buffer中数据长度
 */
extern const ssize_t buffer_data_length(const buffer_t *buffer);

/**
 * 清空buffer
 */
extern void buffer_reset(buffer_t *buffer);

/**
 * 释放buffer
 */
extern void buffer_free(buffer_t *buffer);

#ifdef __cplusplus
}
#endif

#endif
