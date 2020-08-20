//
// Created by rob on 8/19/20.
//

#ifndef HACK_DISASSEMBLER_INSTRUCTIONS_H
#define HACK_DISASSEMBLER_INSTRUCTIONS_H

#include <variant>

#include "A_Type.h"
#include "B_Type.h"
#include "C_Type.h"

namespace hack_dis {
    using Instruction = std::variant<A_Type, B_Type, C_Type>;
}
#endif //HACK_DISASSEMBLER_INSTRUCTIONS_H
