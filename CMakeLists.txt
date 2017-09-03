cmake_minimum_required(VERSION 3.3)
project(about-c-lang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES
#        data-structure/linked-list/linked_list.c
#        data-structure/linked-list/linked_list.h
#        data-structure/list/list.c
#        data-structure/list/list.h
#        syntax/io_char/guess.c
        data-structure/queue/queue.c
        data-structure/queue/queue.h
        data-structure/queue/_test_.c
)

add_executable(about-c-lang ${SOURCE_FILES})