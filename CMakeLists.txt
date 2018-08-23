CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(gowild-coap)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(common)

add_subdirectory(common/test)

add_executable(hello main.c)
