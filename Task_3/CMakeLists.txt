cmake_minimum_required(VERSION 2.8)

project(task_3)

set(SOURCE_EXE main.cpp)

add_executable(main ${SOURCE_EXE})

target_link_libraries(main Manipulator)	