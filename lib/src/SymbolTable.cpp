//
// Created by rob on 8/19/20.
//
#include "hack_dis/SymbolTable.h"
#include <iostream>

namespace hack_dis {
    void SymbolTable::insert_label_location(int loc) {
        static int unique_count = 0;

        //is this already known to be a label?
        if (loc2label.find(loc) != loc2label.end()) {
            //already known, nothing to do
            return;
        }

        std::string new_label = "LABEL_" + std::to_string(unique_count++);

        label2loc.emplace(new_label, loc);
        loc2label.emplace(loc, new_label);
    }

    std::ostream &operator<<(std::ostream &os, const SymbolTable &obj) {
        os << "Symbol Table:\n";
        for(auto [k,v] : obj.label2loc) {
            os << k << " : " << v << '\n';
        }
        return os;
    }
}