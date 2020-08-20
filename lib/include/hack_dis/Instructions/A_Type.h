//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_A_TYPE_H
#define HACK_DISASSEMBLER_A_TYPE_H

#include <string>
#include <iosfwd>

namespace hack_dis {

    class HackLine;
    class SymbolTable;

    struct A_Type {

        //literal value held in the instruction
        int value;

        int line_loc; //line location in original source, zero-indexed
        int inst_loc; //location in the instruction stream, zero-indexed

        //Construct an A-Type from the given line
        explicit A_Type(const HackLine &);

        [[nodiscard]] std::string to_string() const;
        [[nodiscard]] std::string to_string(const SymbolTable&) const;
        [[nodiscard]] std::string to_binary_format(const SymbolTable&) const;

        //Identify if the given line contains an A-Type
        //Does NOT verify if the symbol is valid
        static bool identify(const HackLine &);

        //Pretty-print the instruction
        friend std::ostream &operator<<(std::ostream &, const A_Type &);
    };
}

#endif //HACK_DISASSEMBLER_A_TYPE_H
