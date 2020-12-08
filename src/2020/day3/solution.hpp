#include "../../file_reader.hpp"
#include <cstdint>
#include <string>
#include <algorithm>


std::uint64_t trees_on_slope(const std::vector<std::string>& lines, std::uint64_t x_step, std::uint64_t y_step){
  std::uint64_t result = 0;

  std::uint64_t x = x_step;
  for(std::uint64_t y = y_step; y < lines.size() ; y+=y_step, x+=x_step){
    std::uint64_t actual_x = x%lines[0].size();
    if(lines[y][actual_x] == '#'){
      ++result;
    }
  }
	return result;
}

std::uint64_t aoc2020solution_3(const char* file_name, const std::vector<std::pair<size_t, size_t>>& slopes){
  auto lines = get_lines(file_name);
std::uint64_t result = 1;
  for(const auto& x_y : slopes){
    result *= trees_on_slope(lines, x_y.first, x_y.second);
  }

  std::cout << result << std::endl;
  return result; 
}

void aoc2020_test_3(){
  aoc2020solution_3("./input/2020/day3/test.txt", {{3,1}});
  aoc2020solution_3("./input/2020/day3/day3.txt", {{3,1}});
  aoc2020solution_3("./input/2020/day3/day3.txt", {{1,1}, {3,1}, {5,1}, {7,1}, {1,2}});
}
