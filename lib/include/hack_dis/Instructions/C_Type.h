//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_C_TYPE_H
#define HACK_DISASSEMBLER_C_TYPE_H

#include <string>
#include <string_view>
#include <iosfwd>


namespace hack_dis {

    class HackLine;
    class SymbolTable;

    struct C_Type {
        std::string comp_mnemonic;
        std::string dest_mnemonic;
        int line_loc; //line location in original source, zero-indexed
        int inst_loc; //location in the instruction stream, zero-indexed

        explicit C_Type(const HackLine &);

        [[nodiscard]] std::string to_string() const;
        [[nodiscard]] std::string to_string(const SymbolTable&) const;
        [[nodiscard]] std::string to_binary_format(const SymbolTable&) const;

        static bool identify(const HackLine &);

        friend std::ostream &operator<<(std::ostream &, const C_Type &);
    };
}

#endif //HACK_DISASSEMBLER_C_TYPE_H
