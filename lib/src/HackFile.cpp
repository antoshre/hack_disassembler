//
// Created by rob on 8/19/20.
//

#include "hack_dis/HackFile.h"
#include "string_utils.h"

namespace hack_dis {
    HackFile::HackFile(std::istream &input) {
        int linenum = 0;
        std::string temp;
        while(std::getline(input, temp)) {
            trim_inplace(temp);
            original.emplace_back(linenum, linenum, temp); //line#, inst#, instruction
            linenum += 1;
        }
    }
}