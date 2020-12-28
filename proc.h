#pragma once

#include <vector>
using std::vector;
using address = unsigned int; 

enum class OperType {
    ADD, NAND, LW, SW,
    BEQ, JALR, HALT,
    // new arifmetic operations
    DIV,    //
    SUB,    //
    XSUB,   //
    // new logic operations
    SHL,    //
    ROL,    //
    NOT,    //
    // new jump operations
    JMA,    //
    JMNBE,  //
};

enum class ArgType {
    REG,    // register - 0..3
    ADDR,   // address  - 0..255
    ANY,    // any type 
};

struct Operation {
    OperType type;
    mutable int arg_num;
    vector<ArgType> arg_type;
    Operation (OperType type, vector<ArgType> arg_type) : type(type), arg_num(arg_type.size()), arg_type(arg_type) {}
    Operation (const Operation &oper) = default;
    Operation (Operation &&oper) = default;
    Operation () = default;
};

union Operation_Number {
    unsigned short value;
    struct {
        unsigned short opcode : 4;  // opcode 0..3
        unsigned short arg_1 : 3;   // reg 0..7
        unsigned short arg_2 : 3;   // reg 0..7
        unsigned short arg_3 : 6;   // reg 0..7 or addr 0..63
    } parts;
};

//