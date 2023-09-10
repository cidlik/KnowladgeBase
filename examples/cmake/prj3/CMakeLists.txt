cmake_minimum_required(VERSION 3.20)
project(prj3)

execute_process(
    COMMAND pwd
    OUTPUT_VARIABLE HEAD_PATH
)
string(STRIP ${HEAD_PATH} HEAD_PATH)
message(HEAD_PATH=${HEAD_PATH})

add_subdirectory(subprj1)
add_subdirectory(subprj2)
