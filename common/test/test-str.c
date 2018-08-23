#include <string.h>

#include "../log.h"
#include "../str.h"

int main(int argc,char *argv[])
{
    str_t *str = str_new(2);
    str_set(str,"ab",strlen("ab"));

    DEBUG("test-log","data:%s",str->s);
    str_free(&str);
    return 0;
}
