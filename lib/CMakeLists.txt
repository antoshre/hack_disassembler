cmake_minimum_required(VERSION 3.17)
project(hack_disassembler_lib)

set(LIB_SOURCES
        src/HackFile.cpp
        src/AST.cpp
        src/Instructions/A_Type.cpp
        src/Instructions/B_Type.cpp
        src/Instructions/C_Type.cpp
        src/SymbolTable.cpp
)

add_library(hack_disassembler ${LIB_SOURCES})
#Force C++20 compat.  Could probably roll back to C++17 but std::variant is a hard req
target_compile_features(hack_disassembler PUBLIC cxx_std_20)
target_include_directories(hack_disassembler PUBLIC include PRIVATE src)