cmake_minimum_required(VERSION 3.16)
project(argparser)

add_compile_options(-DDEBUG=0)

add_executable(argparser src/main.c)
