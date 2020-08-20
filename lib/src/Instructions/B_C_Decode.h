//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_B_C_DECODE_H
#define HACK_DISASSEMBLER_B_C_DECODE_H

#include <unordered_map>
#include <string>

namespace hack_dis::detail {
    //Raw Comp Mnemonic decode table:
    //a | cccccc -> comp mnemonic
    static std::unordered_map<std::string, std::string> comp_decode = {
            {"0101010", "0"},
            {"0111111", "1"},
            {"0111010", "-1"},
            {"0001100", "D"},
            {"0110000", "A"},
            {"0001101", "!D"},
            {"0110001", "!A"},
            {"0001111", "-D"},
            {"0110011", "-A"},
            {"0011111", "D+A"},
            {"0110111", "A+1"},
            {"0001110", "D-1"},
            {"0110010", "A-1"},
            {"0000010", "D+A"},
            {"0010011", "D-A"},
            {"0000111", "A-D"},
            {"0000000", "D&A"},
            {"0010101", "D|A"},
            {"1110000", "M"},
            {"1110001", "!M"},
            {"1110011", "-M"},
            {"1110111", "M+1"},
            {"1110010", "M-1"},
            {"1000010", "D+M"},
            {"1010011", "D-M"},
            {"1000111", "M-D"},
            {"1000000", "D&M"},
            {"1010101", "D|M"},
    };

    static std::unordered_map<std::string, std::string> dest_decode = {
            {"000", "null"},
            {"001", "M"},
            {"010", "D"},
            {"011", "MD"},
            {"100", "A"},
            {"101", "AM"},
            {"110", "AD"},
            {"111", "AMD"}
    };

    static std::unordered_map<std::string, std::string> jump_decode = {
            {"000", "null"},
            {"001", "JGT"},
            {"010", "JEQ"},
            {"011", "JGE"},
            {"100", "JLT"},
            {"101", "JNE"},
            {"110", "JLE"},
            {"111", "JMP"}
    };
}

#endif //HACK_DISASSEMBLER_B_C_DECODE_H
