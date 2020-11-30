cmake_minimum_required(VERSION 3.14)
project(interpreter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(plugin)

set (SRC_LIST
    src/xmlinterp.cpp
    src/main.cpp
    src/Init.cpp src/LibInterface.cpp src/Set4LibInterfaces.cpp src/Scene.cpp src/klient.cpp inc/AccessControl.hh inc/Port.hh src/Sender.cpp inc/Sender.h inc/klient.h)

include_directories(inc config)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib dl xerces-c -pthread Interp4Move Interp4Set Interp4Pause Interp4Rotate)