cmake_minimum_required(VERSION 3.20)
message(STATUS "Configuring tilemap unit tests")

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

add_executable(MapReaderUnitTest)
target_sources(MapReaderUnitTest
        PRIVATE
        MapReaderUnitTest.cpp)
target_link_libraries(MapReaderUnitTest
        PRIVATE
        gtest_main
        tilemap
        nlohmann_json::nlohmann_json)

add_test(NAME MapReaderUnitTest
        COMMAND MapReaderUnitTest
        WORKING_DIRECTORY $<TARGET_FILE_DIR:MapReaderUnitTest>)

add_custom_command(TARGET MapReaderUnitTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/map.json"
        $<TARGET_FILE_DIR:MapReaderUnitTest>)