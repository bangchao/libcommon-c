#ifndef COMMON_LOG_H
#define COMMON_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>

typedef int common_log_level_t;
#define COMMON_LOG_LEVEL_INFO 0
#define COMMON_LOG_LEVEL_DEBUG 1
#define COMMON_LOG_LEVEL_WARN 2
#define COMMON_LOG_LEVEL_ERROR 3

extern void common_log_print_impl(common_log_level_t level, const char* tag,  const char *format,...);
extern void set_log_level(common_log_level_t level);

#ifdef DEBUG_ANDROID
    #include <android/log.h>
    #define __common_log_print(level,tag,fmt,arg...) __android_log_print(level,tag,fmt,##arg)
    #undef COMMON_LOG_LEVEL_INFO
    #undef COMMON_LOG_LEVEL_DEBUG
    #undef COMMON_LOG_LEVEL_WARN
    #undef COMMON_LOG_LEVEL_ERROR

    #define COMMON_LOG_LEVEL_INFO  ANDROID_LOG_INFO
    #define COMMON_LOG_LEVEL_DEBUG ANDROID_LOG_DEBUG
    #define COMMON_LOG_LEVEL_WARN  ANDROID_LOG_WARN
    #define COMMON_LOG_LEVEL_ERROR ANDROID_LOG_ERROR
#else
    #define __common_log_print(level,tag,fmt,arg...) common_log_print_impl(level,tag,fmt,##arg)
#endif

#ifdef DEBUG_DETAIL
    #define __common_log_detail(level,tag,fmt,arg...) __common_log_print(level,tag," [%s:%s[%d]] "fmt,__FILE__,__func__,__LINE__,##arg)
#else
    #define __common_log_detail(level,tag,fmt,arg...) __common_log_print(level,tag," [%s:%d] "fmt,__func__,__LINE__, ##arg)
#endif

#define INFO(tag,fmt,arg...)    __common_log_detail(COMMON_LOG_LEVEL_INFO, tag, fmt, ##arg)
#define DEBUG(tag,fmt,arg...)   __common_log_detail(COMMON_LOG_LEVEL_DEBUG,tag, fmt, ##arg)
#define WARN(tag,fmt,arg...)    __common_log_detail(COMMON_LOG_LEVEL_WARN, tag, fmt, ##arg)
#define ERROR(tag,fmt,arg...)   __common_log_detail(COMMON_LOG_LEVEL_ERROR,tag, fmt, ##arg)

#ifdef __cplusplus
}
#endif

#endif
