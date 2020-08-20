//
// Created by rob on 8/19/20.
//

#include "hack_dis/HackLine.h"
#include "hack_dis/Instructions/A_Type.h"

#include <string>

namespace hack_dis {

    A_Type::A_Type(const HackLine &line) : line_loc(line.line_num), inst_loc(line.inst_num), value(std::stoi(line.inst.substr(1), nullptr, 2)) {
    }

    bool A_Type::identify(const HackLine &line) {
        return line.inst.starts_with('0');
    }

    std::ostream &operator<<(std::ostream &os, const A_Type &obj) {
        os << "A-Type(" << obj.value << ")";
        return os;
    }
}