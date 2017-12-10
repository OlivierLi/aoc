#include "../file_reader.hpp"
#include <set>
#include <string>
#include <algorithm>

std::string solution_7(const char* file_name){
    auto lines = get_lines(file_name);
    auto parents = read_col<std::string>(lines, 0); 
    auto children_tokens = read_col<std::string>(lines, 3);

    std::set<std::string> parents_set(parents.cbegin(), parents.cend());
    std::set<std::string> children_set;

    for(auto tokens : children_tokens){
        for(auto child : parse_csv(tokens)){
            children_set.insert(child);
        }
    }

    std::vector<std::string> diff;
    std::set_difference(parents_set.begin(), parents_set.end(), children_set.begin(), children_set.end(), std::inserter(diff, diff.begin()));

    assert(diff.size() == 1);

    return diff[0];
}

void test_7(){
    assert(solution_7("./input/day7_test.txt") == "tknk");
    assert(solution_7("./input/day7.txt") == "ahnofa");
}
