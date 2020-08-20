# hack_disassembler
Hack assembly disassembler.

Disassembles Hack .hack files into an AST suitable for consumption by another process.

Hack is an academic assembly language created for the [nand2tetris](https://www.nand2tetris.org/project06) course.

This project deviates from the official material by making a distinction between C-Type instructions that can branch and those that cannot.
  Branching instructions are decoded as a pseudo instruction called 'B-Type'.

Status: Decoding to instructions is complete, but recovering labels and control flow is still being implemented.

## Installation

Clone the repo.  Requires no external deps.  

## Requirements 

Requires C++17.

## Usage

`examples\print_ast.cpp`:

`print_ast examples/mult.hack`:

```
Original		|	Decoded
0000000000000010	|	A-Type(2)
1110101010001000	|	C-Type(M=0)
0000000000000000	|	A-Type(0)
1111110000010000	|	C-Type(D=M)
0000000000010000	|	A-Type(16)
1110001100001000	|	C-Type(M=D)
0000000000010000	|	A-Type(16)
1111110000010000	|	C-Type(D=M)
0000000000010010	|	A-Type(18)
1110001100000010	|	B-Type(D;JEQ)
0000000000000001	|	A-Type(1)
1111110000010000	|	C-Type(D=M)
0000000000000010	|	A-Type(2)
1111000010001000	|	C-Type(M=D+M)
0000000000010000	|	A-Type(16)
1111110010001000	|	C-Type(M=M-1)
0000000000000110	|	A-Type(6)
1110101010000111	|	B-Type(0;JMP)
0000000000010010	|	A-Type(18)
1110101010000111	|	B-Type(0;JMP)

Symbol Table:
LABEL_0 : 18
LABEL_1 : 6
```