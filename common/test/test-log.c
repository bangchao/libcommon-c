#include "../log.h"

int main(int argc,char *argv[])
{
    int i = 12;
    INFO("aaa","bbb:%d",i);
    DEBUG("aaa","bbb:%d",i);
    WARN("aaa","bbb:%d",i);
    ERROR("aaa","bbb:%d",i);
    return 0;
}
