#~/bin/bash
if [ ! -d "out" ];then
    mkdir ./out
fi

cd out && cmake -DCMAKE_BUILD_TYPE=Debug -DDEBUG_DETAIL=1 ..  && make VERBOSE=1
