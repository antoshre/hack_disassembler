//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_HACKFILE_H
#define HACK_DISASSEMBLER_HACKFILE_H

#include <istream>
#include <vector>
#include <string>

#include "hack_dis/HackLine.h"
namespace hack_dis {
    struct HackFile {
        std::vector<HackLine> original;
    public:
        explicit HackFile(std::istream&);
    };
}

#endif //HACK_DISASSEMBLER_HACKFILE_H
