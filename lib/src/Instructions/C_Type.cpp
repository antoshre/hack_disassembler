//
// Created by rob on 8/19/20.
//

#include "hack_dis/Instructions/C_Type.h"

#include "hack_dis/HackLine.h"
#include "B_C_Decode.h"

namespace hack_dis {

    C_Type::C_Type(const HackLine &line) {
        //B_Type "binary" is:
        //111accccccdddjjj
        //ddd should be 000 for B-type
        auto comp = line.inst.substr(3,7);
        comp_mnemonic = detail::comp_decode[comp];
        auto dest = line.inst.substr(10,3);
        dest_mnemonic = detail::dest_decode[dest];
    }

    bool C_Type::identify(const HackLine &line) {
        auto jump = line.inst.substr(13,3);
        return jump == "000";
    }

    std::ostream &operator<<(std::ostream &os, const C_Type &obj) {
        os << "C-Type(" << obj.dest_mnemonic << "=" << obj.comp_mnemonic << ")";
        return os;
    }
}