cmake_minimum_required(VERSION 3.20)
project(globus_task)

# C/C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(map_reader)
add_subdirectory(path_finder)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
        PRIVATE
        main.cpp)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        map_reader
        path_finder
        nlohmann_json::nlohmann_json)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/map.json"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)