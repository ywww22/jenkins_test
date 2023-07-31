cmake_minimum_required(VERSION 3.5)
project(CMake_GCov CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/sum.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")

set(SOURCES
    src/main.cc
    src/sum.cc
)

add_executable(sumCovTest ${SOURCES})

add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_command(TARGET gcov
    COMMAND echo "=======GCOV======="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${OBJECT_DIR}
        | grep -A 5 "sum.cc" > CoverageSummary.tmp
    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage)

add_dependencies(gcov sumCovTest)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAR_FILES coverage)

add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/sumCovTest)
set_tests_properties(output_test PROPERTIES PASS_REGULAR_EXPRESSION "0;5;10")