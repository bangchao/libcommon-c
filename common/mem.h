#ifndef COMMON_MEM_H
#define COMMON_MEM_H

extern int memory_manager_init();
extern int memory_manager_destory();
extern int memory_manager_debug();
extern int memory_manager_new_block(void **ptr, size_t size, const char* func,const int line);
extern int memory_manager_free_block(void **ptr, const char* func,const int line);

#define MALLOC(ptr,len) do { memory_manager_new_block(ptr, len, __func__, __LINE__); } while(0)
#define FREE(ptr) do { memory_manager_free_block(ptr, __func__, __LINE__); } while(0)

#endif
