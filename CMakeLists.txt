cmake_minimum_required(VERSION 3.17)
project(hack_disassembler)

add_subdirectory(lib) #hack::disassembler

option(BUILD_EXAMPLES "Build examples" ON)
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()


option(BUILD_TESTING "Build tests" ON)
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif ()