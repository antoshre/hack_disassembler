//
// Created by rob on 8/19/20.
//

#include "hack_dis/AST.h"

#include <ranges>
#include <algorithm>
#include <iostream>

using namespace std::ranges::views;

namespace hack_dis {

    Instruction parse(const HackLine &s) {
        if (A_Type::identify(s)) {
            return A_Type(s);
        }
        if (C_Type::identify(s)) {
            return C_Type(s);
        }
        if (B_Type::identify(s)) {
            return B_Type(s);
        }

        throw std::runtime_error("Cannot parse assembly line: " + std::string(s));
    }

    AST::AST(std::istream &input) : file(input) {
        auto i = file.original | transform([](const HackLine &a) { return parse(a); });
        std::ranges::copy(i, std::back_inserter(instrs));
        //Straighforward decoding finished.

        //Recover trivial label locations
        //Look for A-Types immediately followed by B-Type
        //Loop from begin to end-1, so it++ is always valid Instruction
        //Basically peephole over every 2 instruction window
        for(auto it=instrs.begin(); it != instrs.end()--; it++) {
            auto curr = *it; //current instruction
            auto next = *(it+1); //next instruction

            if (std::holds_alternative<A_Type>(curr)) {
                if (std::holds_alternative<B_Type>(next)) {
                    //curr is A-Type that holds a jump label location
                    auto ainst = std::get<A_Type>(curr);
                    symbols.insert_label_location(ainst.value);
                }
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, const AST &obj) {
        os << "Original\t\t\t|\tDecoded\n";

        for(int i=0; i < obj.instrs.size(); i++) {
            os << obj.file.original[i].inst << "\t|\t";
            std::visit([&os](auto& e){ os << e;}, obj.instrs[i]);
            os << '\n';
        }

        os << obj.symbols << '\n';

        return os;
    }
}