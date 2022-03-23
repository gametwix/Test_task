cmake_minimum_required(VERSION 2.8)

project(task_2)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB Manipulator.cpp)	

add_library(Manipulator STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main Manipulator)	