cmake_minimum_required(VERSION 3.3)
project(c_lang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#    data-structure/linked-list/linked_list.c
#    data-structure/linked-list/linked_list.h
#    data-structure/list/list.c
#    data-structure/list/list.h
#    data-structure/queue/_test_.c
#    data-structure/queue/queue.c
#    data-structure/queue/queue.hSS
#        syntax/io_char/guess.c
        data-structure/tree/tree.c
        data-structure/tree/tree.h
        data-structure/tree/_test_.c
)

add_executable(c_lang ${SOURCE_FILES})