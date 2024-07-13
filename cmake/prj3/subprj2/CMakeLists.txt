cmake_minimum_required(VERSION 3.20)
project(subprj2)

if(DEFINED HEAD_PATH)
    set(INSTALL_PATH ${HEAD_PATH})
else()
    set(INSTALL_PATH ${CMAKE_CURRENT_SOURCE_DIR})
endif()
message(INSTALL_PATH=${INSTALL_PATH})

add_executable(test2 src/main.c)

install(TARGETS test2 DESTINATION ${INSTALL_PATH})
