//
// Created by rob on 8/19/20.
//

#include "hack_dis/hack_dis.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: print_ast [filename.hack]" << '\n';
        return -1;
    }

    std::ifstream file(argv[1], std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << '\n';
        return -2;
    }

    hack_dis::AST ast(file);

    std::cout << ast << std::endl;
}
