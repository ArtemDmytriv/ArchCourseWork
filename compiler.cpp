#include "compiler.h"
#include <iostream>
#include <sstream>

std::vector<std::vector<std::string>> Compiler::tokens;
std::map<std::string, address> Compiler::labels;
std::map<OperType, Operation> Compiler::op_data;

void Compiler::init_compiler() {
    add_operation(OperType::ADD, {ArgType::REG, ArgType::REG, ArgType::ANY});
    add_operation(OperType::NAND, {ArgType::REG, ArgType::REG, ArgType::REG});
    add_operation(OperType::LW, {ArgType::REG, ArgType::REG, ArgType::ADDR});
    add_operation(OperType::SW, {ArgType::REG, ArgType::REG, ArgType::ADDR});
    add_operation(OperType::BEQ, {ArgType::REG, ArgType::REG, ArgType::ADDR});
    add_operation(OperType::JALR, {ArgType::REG, ArgType::REG});
    add_operation(OperType::HALT, {});
}

void Compiler::add_operation(const OperType type, const vector<ArgType> arg_type) {
    if (op_data.find(type) == op_data.end())
        op_data.insert({type, Operation{type, arg_type}});
}

Operation* Compiler::get_operation(const OperType type) {
    if (op_data.find(type) != op_data.end())
        return &op_data[type];
    return nullptr;
}

int Compiler::get_operation_arg_num(const OperType type) {
    if (op_data.find(type) != op_data.end())
        return op_data[type].arg_num;
    return -1;
}

int Compiler::load_tokens_from_file(std::ifstream &fin) {
    std::string line, word;
    int k = 0;

    while (getline(fin, line)) {
        tokens.push_back({}); // push back new empty vector (new line)
        std::istringstream iss(line);
        if (line[0] == ' ') {
            tokens[k].push_back(""); 
        }
        // push words (label, opcode, regs(offset)) not copy comments
        while (iss >> word) {
            tokens[k].push_back(word);
        }
        ++k;  
    }

    return k;
}

bool Compiler::check_and_load_labels() {
    bool is_good = true;
    for (int i = 0; i < tokens.size(); i++) {
        if (!tokens[i][0].empty()) {
            if (labels.find(tokens[i][0]) == labels.end())
                labels.insert(std::make_pair(tokens[i][0], i));
            else {
                is_good = false;
                std::cerr << "Error: duplicating label (" << tokens[i][0] << "): line " << i+1 << "\n";
            }
        }
    }
    return is_good;
}

bool Compiler::check_args() {
    return true;
}