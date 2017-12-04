#include <vector>
#include <fstream>
#include <string>

std::vector<std::string> get_lines(const std::string& file_name){
    std::ifstream my_file(file_name);
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(my_file, line)){
        lines.push_back(line);
    }

    return lines;
}
