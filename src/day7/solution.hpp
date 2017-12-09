#include "../file_reader.hpp"

std::string solution_7(const char* file_name){
    auto lines = get_lines(file_name);
    auto parents = read_col<std::string>(lines, 0); 
    auto children_tokens = read_col<std::string>(lines, 1);

    return "";
}

void test_7(){
    solution_7("./input/day7_test.txt");
}
