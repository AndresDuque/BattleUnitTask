cmake_minimum_required(VERSION 3.20)
project(path_finder)


add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME}
        PRIVATE
        include/Algorithm.h
        src/Algorithm.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(test)