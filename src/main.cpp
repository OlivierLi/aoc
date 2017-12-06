#include <iostream>
#include "file_reader.hpp"
#include "day1/solution.hpp"
#include "day2/solution.hpp"
#include "day3/solution.hpp"

int main(int argc, char**){
    if(argc != 2){
        std::cout << "Only provide the input file name!" << std::endl; 
        return -1;
    }

    //Run the "tests" to validate no solution was broken 
    test_1();
    test_1_2();
    test_2();
    test_3();

    return 0;
}
