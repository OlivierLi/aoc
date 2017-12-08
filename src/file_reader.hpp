#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

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

// Very inneficient function to simply get a column
template<typename T> 
std::vector<T> read_col(const std::vector<std::string>& lines, size_t i){
   
   std::vector<T> col;

   for(const auto& line : lines){
        const auto& vals = parse_line<T>(line);
       assert(i < vals.size());
       col.push_back(vals.at(i));
   } 

   return col;
}
