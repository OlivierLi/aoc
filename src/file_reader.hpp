#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::string> get_lines(const std::string& file_name){
    std::ifstream my_file(file_name);
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(my_file, line)){
        lines.push_back(line);
    }
    return lines;
}

template<typename T> 
std::vector<T> parse_line(const std::string& line){
    std::vector<T> vals;
    std::stringstream stream(line);
    
    while(true){
        T val;
        stream >> val;

        if(!stream){
            break;
        }

        vals.push_back(val);
    }

    return vals;
}
