//
// Created by rob on 8/19/20.
//

#include <stdexcept>
#include "hack_dis/Instructions/B_Type.h"
#include "hack_dis/HackLine.h"

#include "B_C_Decode.h"

namespace hack_dis {

    B_Type::B_Type(const HackLine &line) {
        //B_Type "binary" is:
        //111accccccdddjjj
        //ddd should be 000 for B-type
        auto comp = line.inst.substr(3,7);
        comp_mnemonic = detail::comp_decode[comp];
        auto jump = line.inst.substr(13,3);
        jump_mnemonic = detail::jump_decode[jump];
    }

    bool B_Type::identify(const HackLine &line) {
        auto dest = line.inst.substr(10, 3);
        return dest == "000";
    }

    std::ostream &operator<<(std::ostream &os, const B_Type &obj) {
        os << "B-Type(" << obj.comp_mnemonic << ";" << obj.jump_mnemonic << ")";
        return os;
    }
}