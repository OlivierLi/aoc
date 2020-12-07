#include "../../file_reader.hpp"
#include <cstdint>
#include <string>
#include <algorithm>
#include <regex>


std::uint64_t aoc2020solution_2(const char* file_name, bool part2){
  auto lines = get_lines(file_name);

  std::uint64_t total = 0;
  for(const std::string& line: lines){
    const std::regex pieces_regex("([0-9]+)-([0-9]+) ([a-z]): (.*)");
    std::smatch pieces_match;

    if (std::regex_match(line, pieces_match, pieces_regex)) {

      std::uint64_t min = std::stoi(pieces_match[1].str());
      std::uint64_t max = std::stoi(pieces_match[2].str());
      char c = pieces_match[3].str().front();
      std::string password = pieces_match[4].str();

      if(!part2){
        std::uint64_t count = std::count(password.cbegin(), password.cend(), c);
        if(count <= max && count >= min){
          ++total;
        }
      }
      else{
        std::uint64_t hits = 0;
        for(size_t i : {min, max}){
          if(password[i-1] == c){
            ++hits;
          }
        }
        if(hits == 1){
          ++total;
        }
      }
    }
  }

  return total;
}

void aoc2020_test_2(){
  assert(aoc2020solution_2("./input/2020/day1/day2.txt", false) == 600);
  assert(aoc2020solution_2("./input/2020/day1/day2.txt", true) == 245);
}
