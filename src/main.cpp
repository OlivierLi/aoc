#include <iostream>
#include "file_reader.hpp"
#include "day1/solution.hpp"

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Only provide the input file name!" << std::endl; 
        return -1;
    }

    //Test the provided input
    test_1_2();

    const std::vector<std::string>& lines = get_lines(argv[1]); 
    for(const auto& line: lines){
        std::cout << solution_1_2(line) << std::endl; 
    }

    return 0;
}
