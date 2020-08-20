//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_AST_H
#define HACK_DISASSEMBLER_AST_H

#include "HackFile.h"
#include "Instructions/Instructions.h"
#include "SymbolTable.h"
#include <vector>
#include <iosfwd>

namespace hack_dis {
    class AST {
        const HackFile file;
        std::vector<Instruction> instrs;

        SymbolTable symbols;
    public:
        explicit AST(std::istream&);

        friend std::ostream& operator<<(std::ostream&, const AST&);
    };
}

#endif //HACK_DISASSEMBLER_AST_H
