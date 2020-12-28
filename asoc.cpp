#include "proc.h"
#include "compiler.h"

#include <fstream>
#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[]) {

    if (argc != 2) { 
        std::cerr << "Incorrect number of argumnets\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream progfile(argv[1]);
    if (progfile.fail()) {
        std::cerr << "Error: Cannot find file: " << argv[1] << "\n"; 
        exit(EXIT_FAILURE);    
    }

    Compiler::init_compiler();

    int line_k = Compiler::load_tokens_from_file(progfile);

    bool label = Compiler::check_and_load_labels();
    
    std::cout << std::boolalpha << line_k << ' ' << label << '\n';
    // std::map<std::string, address> labels{};
    // vec2d_str vec{};

    // size_t line_k = read_file_into_vec(progfile, vec);

    // // check_labels
    // if (!check_labels(vec, labels)) {
    //     std::cerr << "Error: Bad labels\n";
    // }
    
    // for (size_t i = 0; i < vec.size(); i++) {
    //     for (size_t j = 0; j < vec[i].size(); j++) {
    //         std::cout << "\"" << vec[i][j] <<"\" ";
    //     }
    //     std::cout << "\n";
    // }


    
    
    return line_k;
}


