cmake_minimum_required(VERSION 3.16)
project(test1)

add_library (common ../common/common.c)

add_executable(test1 test1.c)
target_link_libraries(test1 PUBLIC common)
