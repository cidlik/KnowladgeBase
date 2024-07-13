cmake_minimum_required(VERSION 3.20)
project(prj2)

set(SOURCE_EXE src/main.c)
set(SOURCE_LIB src/custom-lib.c)

add_library(custom-lib ${SOURCE_LIB})
add_executable(test ${SOURCE_EXE})

target_include_directories(custom-lib PRIVATE include)
target_include_directories(test PRIVATE include)
target_link_libraries(test custom-lib)

install(TARGETS test DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
