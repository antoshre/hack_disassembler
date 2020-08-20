//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_HACKLINE_H
#define HACK_DISASSEMBLER_HACKLINE_H

#include <string>
#include <iostream>

namespace hack_dis {
    struct HackLine {
        //The line number from the original source, comments and whitespace included
        int line_num;
        //The logical instruction number
        int inst_num;
        std::string inst;

        friend std::iostream& operator<<(std::iostream &os, const HackLine &obj) {
            os << "Line(" << obj.line_num << ":" << obj.inst_num << ", " << obj.inst << ")";
            return os;
        }

        explicit operator std::string() const {
            return "Line(" + std::to_string(line_num) + ":" + std::to_string(inst_num) + ", " + inst + ")";
        }
    };
}

#endif //HACK_DISASSEMBLER_HACKLINE_H
