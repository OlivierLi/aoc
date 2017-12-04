#include <iostream>
#include "file_reader.hpp"
#include "day1/solution.hpp"
#include "day2/solution.hpp"

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Only provide the input file name!" << std::endl; 
        return -1;
    }

    //Run the "tests" to validate no solution was broken 
    test_1();
    test_1_2();
    test_2();

    const std::vector<std::string>& lines = get_lines(argv[1]); 
    std::cout << solution_2(lines, divisible) << std::endl; 

    return 0;
}
