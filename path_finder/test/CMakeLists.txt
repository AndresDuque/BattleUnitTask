cmake_minimum_required(VERSION 3.20)
message(STATUS "Configuring map_reader unit tests")

include(CTest)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


add_executable(GraphUnitTest)
target_sources(GraphUnitTest
        PRIVATE
        AlgorithmUnitTest.cpp)
target_link_libraries(GraphUnitTest
        PRIVATE
        gtest_main
        map_reader
        nlohmann_json::nlohmann_json
        path_finder)

add_test(NAME GraphUnitTest
        COMMAND GraphUnitTest
        WORKING_DIRECTORY $<TARGET_FILE_DIR:GraphUnitTest>)

add_custom_command(TARGET GraphUnitTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/map.json"
        $<TARGET_FILE_DIR:GraphUnitTest>)