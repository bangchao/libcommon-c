CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(PROJECT common)
AUX_SOURCE_DIRECTORY(. PROJECT_SRCS)

ADD_LIBRARY(${PROJECT} STATIC ${PROJECT_SRCS})
SET_TARGET_PROPERTIES(${PROJECT} PROPERTIES OUTPUT_NAME "${PROJECT}")
