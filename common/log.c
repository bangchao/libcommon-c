#include "log.h"
#include <time.h>

/* this array has the same order as the type log_t */
static char *log_tags[] = {
    "INFO",
    "DEBUG",
    "WARN",
    "ERROR",
};

static inline size_t print_timestamp(char *s, size_t len) {
    struct tm *tmp;
    time_t now = 0;
    time(&now);
    tmp = localtime(&now);
    return strftime(s, len, "%b %d %H:%M:%S", tmp);
}

static common_log_level_t max_log_level = COMMON_LOG_LEVEL_INFO;

void set_log_level(common_log_level_t level)
{
    max_log_level = level;
}

void common_log_print_impl(common_log_level_t level, const char *tag, const char *format,...)
{
    if(level < max_log_level) {
        return;
    }
    char timebuf[32] = {0};
    print_timestamp(timebuf,sizeof(timebuf));
    fprintf(stdout,"%s ",timebuf);
    if(level <= COMMON_LOG_LEVEL_ERROR) {
        fprintf(stdout, " %s",log_tags[level]);
    }
    fprintf(stdout," %s",tag);

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fflush(stdout);
    fprintf(stdout,"\n");
}
