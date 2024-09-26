cmake_minimum_required(VERSION 3.16)
project(copystr)

add_library (common ../common/common.c)

add_executable(copystr copystr.c)
target_link_libraries(copystr PUBLIC common)
