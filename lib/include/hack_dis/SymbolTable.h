//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_SYMBOLTABLE_H
#define HACK_DISASSEMBLER_SYMBOLTABLE_H

#include <map>
#include <string>
#include <iosfwd>

namespace hack_dis {
    class SymbolTable {
        std::map<int, std::string> loc2label;
        std::map<std::string, int> label2loc;
    public:
        void insert_label_location(int loc);

        friend std::ostream& operator<<(std::ostream&, const SymbolTable&);
    };


}

#endif //HACK_DISASSEMBLER_SYMBOLTABLE_H
