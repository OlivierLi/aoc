#include "../../file_reader.hpp"
#include <cstdint>
#include <set>
#include <string>
#include <algorithm>


std::uint64_t aoc2020solution_1(const char* file_name){
    auto lines = get_lines(file_name);
    auto numbers = read_col<std::int64_t>(lines, 0); 
    constexpr int64_t target_sum{2020};

    for(size_t i=0;i<numbers.size();++i){
      for(size_t j=i;j<numbers.size();++j){
        int64_t first = numbers[i];
        int64_t second = numbers[j];

        if(first + second == target_sum){
          return first*second;
        }

      } 
    } 

    return 0;
}

std::uint64_t aoc2020solution_1_2(const char* file_name){
    auto lines = get_lines(file_name);
    auto numbers = read_col<std::int64_t>(lines, 0); 
    constexpr int64_t target_sum{2020};

    for(size_t i=0;i<numbers.size();++i){
      for(size_t j=0;j<numbers.size();++j){
        for(size_t k=0;k<numbers.size();++k){
          int64_t first = numbers[i];
          int64_t second = numbers[j];
          int64_t third = numbers[k];

          if(first + second + third == target_sum){
            return first*second*third;
          }
        }
      } 
    } 

    return 0;
}

void aoc2020_test_1(){
  assert(aoc2020solution_1("./input/2020/day1/day1.txt") == 800139);
  assert(aoc2020solution_1_2("./input/2020/day1/day1.txt") == 59885340);
}
