CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

FILE(GLOB my_test_list *.c)
FOREACH( testsourcefile ${my_test_list} )
    # I used a simple string replace, to cut off .cpp.
    MESSAGE(${testsourcefile})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" testname ${testsourcefile})
    MESSAGE(${testname})
    ADD_EXECUTABLE( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    TARGET_LINK_LIBRARIES(${testname} common)
ENDFOREACH( testsourcefile ${my_test_list} )
