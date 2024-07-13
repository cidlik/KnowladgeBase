pkg_check_modules(GSTBASE REQUIRED gstreamer-base-1.0)
include_directories("${GSTBASE_INCLUDE_DIRS}")
link_directories("${GSTBASE_LIBRARY_DIRS}")

add_executable(test-app test-app.cpp)

target_link_libraries(test-app
                      ${GSTBASE_LIBRARIES})
