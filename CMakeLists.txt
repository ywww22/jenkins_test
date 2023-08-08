cmake_minimum_required(VERSION 3.5)
project(gtest-prac)

# setting for coverage
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
add_compile_options(--coverage)
link_libraries(gcov)

# build sum library
set(TARGET_LIB sum)
add_library(${TARGET_LIB} src/sum.cc)

# build sum program
set(TARGET_APP sum_app)
add_executable(${TARGET_APP} src/main.cc)
#target_include_directories(${TARGET_APP} ./inc)
#target_link_directories(${TARGET_APP} ./inc)
target_link_libraries(${TARGET_APP} ${TARGET_LIB})

# build test code
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)
endif()

set(TARGET_TEST run_sum_tests)
add_executable(${TARGET_TEST} test/sumTest.cc)
target_link_libraries(${TARGET_TEST} ${TARGET_LIB} gtest gtest_main)

# run test and create coverage report
set(COVERAGE_REPORT_DIR coverage_report)
set(GCOV_FILE_DIR build/CMakeFiles/${TARGET_LIB}.dir/src)
add_custom_target(sumTest
                    COMMENT "Execute all unit test cases and generate coverage report"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    DEPENDS ${TARGET_TEST}
                    COMMAND mkdir -p ${COVERAGE_REPORT_DIR}
                    COMMAND gcovr ${GCOV_FILE_DIR} -r src --html-details -o ${COVERAGE_REPORT_DIR}/gcov.html
)