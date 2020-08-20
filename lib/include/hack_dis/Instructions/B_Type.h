//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_B_TYPE_H
#define HACK_DISASSEMBLER_B_TYPE_H

#include <string>
#include <string_view>
#include <iosfwd>


namespace hack_dis {

    class HackLine;
    class SymbolTable;

    struct B_Type {
        std::string comp_mnemonic;
        std::string jump_mnemonic;
        int line_loc; //line location in original source, zero-indexed
        int inst_loc; //location in the instruction stream, zero-indexed

        explicit B_Type(const HackLine &);

        [[nodiscard]] std::string to_string() const;
        [[nodiscard]] std::string to_string(const SymbolTable&) const;
        [[nodiscard]] std::string to_binary_format(const SymbolTable&) const;

        static bool identify(const HackLine &);

        friend std::ostream &operator<<(std::ostream &, const B_Type &);
    };
}
#endif //HACK_DISASSEMBLER_B_TYPE_H
