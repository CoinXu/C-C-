cmake_minimum_required(VERSION 3.3)
project(about_c_lang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES
#        data_structure/linked-list/linked_list.c
#        data_structure/linked-list/linked_list.h
#        data_structure/list/list.c
#        data_structure/list/list.h
#        syntax/io_char/guess.c
        queue/queue.c
        queue/queue.h
        queue/_test_.c
)

add_executable(about_c_lang ${SOURCE_FILES})