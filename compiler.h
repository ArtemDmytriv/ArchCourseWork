#pragma once

#include "proc.h"

#include <fstream>
#include <map>

class Compiler { 
public:
const std::string str_fill = ".fill";
const std::map<std::string, OperType> str_map = {
    {"add", OperType::ADD},
    {"nand", OperType::NAND},
    {"lw", OperType::LW},
    {"sw", OperType::SW},
    {"beq", OperType::BEQ},
    {"jalr", OperType::JALR},
    {"halt", OperType::HALT},
    {"div", OperType::DIV},
    {"sub", OperType::SUB},
    {"shl", OperType::SHL},
    {"rol", OperType::ROL},
    {"not", OperType::NOT},
    {"jma", OperType::JMA},
    {"jmnbe", OperType::JMNBE},
};

static void init_compiler();

static void add_operation(const OperType type, const vector<ArgType> arg_type);
static Operation* get_operation(const OperType type);
static int get_operation_arg_num(const OperType type);

static int load_tokens_from_file(std::ifstream &fin);

static bool check_and_load_labels();
static bool check_args();

private:
static std::vector<std::vector<std::string>> tokens;
static std::map<std::string, address> labels;
static std::map<OperType, Operation> op_data;

};