#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../buffer.h"

int main(int argc, char* argv[])
{
    buffer_t *buffer = buffer_new(12);

    assert(buffer_data_length(buffer) == 0);

    buffer_append(buffer,"abcdefg",7);
    assert(buffer_data_length(buffer) == 7 && !strncmp(buffer_data(buffer),"abcdefg",7));
    printf("append abcdefg %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));

    buffer_append(buffer,"hijklmno",8);
    printf("append hijklmno %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 12 && !strncmp(buffer_data(buffer),"abcdefghijkl",12));

    buffer_reset(buffer);
    assert(buffer_data_length(buffer) == 0);
    printf("buffer reset %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));

    buffer_append(buffer,"abcd",4);
    printf("buffer append abcd %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));

    printf("testing remove 1.......\n");
    buffer_remove(buffer,-1,0);
    printf("buffer remove -1,0 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 4 && !strncmp(buffer_data(buffer),"abcd",4));

    printf("testing remove 2.......\n");
    buffer_remove(buffer,4,2);
    printf("buffer remove 4,2 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 4 && !strncmp(buffer_data(buffer),"abcd",4));

    printf("testing remove 3.......\n");
    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,0,4);
    printf("buffer remove 0,4 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 0);

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,0,3);
    printf("buffer remove 0,3 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 1 && !strncmp(buffer_data(buffer),"d",1));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,0,2);
    printf("buffer remove 0,2 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 2 && !strncmp(buffer_data(buffer),"cd",2));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,0,1);
    printf("buffer remove 0,1 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 3 && !strncmp(buffer_data(buffer),"bcd",3));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,0,0);
    printf("buffer remove 0,0 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 4 && !strncmp(buffer_data(buffer),"abcd",4));

    printf("testing remove 4.......\n");
    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,1,3);
    printf("buffer remove 1,3 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 1 && !strncmp(buffer_data(buffer),"a",1));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,1,2);
    printf("buffer remove 1,2 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 2 && !strncmp(buffer_data(buffer),"ad",2));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,1,1);
    printf("buffer remove 1,1 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 3 && !strncmp(buffer_data(buffer),"acd",3));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,1,0);
    printf("buffer remove 1,0 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 4 && !strncmp(buffer_data(buffer),"abcd",4));

    printf("testing remove 5.......\n");
    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,2,3);
    printf("buffer remove 2,3 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 2 && !strncmp(buffer_data(buffer),"ab",2));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,2,2);
    printf("buffer remove 2,2 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 2 && !strncmp(buffer_data(buffer),"ab",2));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,2,1);
    printf("buffer remove 2,1 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));
    assert(buffer_data_length(buffer) == 3 && !strncmp(buffer_data(buffer),"abd",3));

    buffer_reset(buffer);
    buffer_append(buffer,"abcd",4);
    buffer_remove(buffer,2,0);
    printf("buffer remove 2,0 %s %zd\n",buffer_data(buffer),buffer_data_length(buffer));

    buffer_free(buffer);

    return 0;
}
