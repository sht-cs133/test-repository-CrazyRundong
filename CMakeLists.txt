CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(hist_median)
SET(CMAKE_CXX_STANDARD 14)

## Setup gtest
FUNCTION(set_gtest)
    execute_process(
            COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
    )
    if(result)
        message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()

    execute_process(
            COMMAND ${CMAKE_COMMAND} --build .
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
    )
    if(result)
        message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    add_subdirectory(
            ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
            ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
            EXCLUDE_FROM_ALL
    )

    if (CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories("${gtest_SOURCE_DIR}/include")
    endif()
ENDFUNCTION()

configure_file(cmake/get_gtest.cmake.in googletest-download/CMakeLists.txt)
set_gtest()

## Major project
INCLUDE_DIRECTORIES(include)
FILE(GLOB src src/*.cpp)

SET(TEST_EXE_NAME "${PROJECT_NAME}_test")
FILE(GLOB test_src test/*.cpp)
LIST(APPEND test_src ${src})

# ADD_EXECUTABLE(${PROJECT_NAME} ${src})
ADD_EXECUTABLE(${TEST_EXE_NAME} ${test_src})
TARGET_LINK_LIBRARIES(${TEST_EXE_NAME} gtest)
