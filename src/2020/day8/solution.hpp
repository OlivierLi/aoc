#include "../../file_reader.hpp"
#include <cstdint>
#include <cassert>
#include <cstdlib>
#include <iterator>
#include <string>
#include <algorithm>
#include <type_traits>

namespace {
  enum class Inst{
    NOP,
    ACC,
    JMP,
  };

  struct Line {
    Inst inst;
    std::int64_t value;
    bool visited = false;
  };

  Line parse(const std::string& line){
    Inst inst;
    switch(line[0]){
      case 'n':
        inst = Inst::NOP;
        break;
      case 'a':
        inst = Inst::ACC;
        break;
      case 'j':
        inst = Inst::JMP;
        break;
      default:
        // Not reached.
        std::abort();
    }

    return  {inst, std::stoi(line.substr(4, line.size()-4)), false};
  }
}

void flip(Line& line){
  if(line.inst == Inst::JMP){
    line.inst = Inst::NOP;
  }
  else if(line.inst == Inst::NOP){
    line.inst = Inst::JMP;
  }
}

void reset_visited(std::vector<Line>& parsed_lines){
  for(Line& line: parsed_lines){
    line.visited = false;
  }
}

std::pair<bool, std::int64_t> run_until_looping(std::vector<Line>& parsed_lines){
  std::int64_t result = 0;

  size_t i = 0;
  while(i<parsed_lines.size()){
    Line& line = parsed_lines[i];
    if(line.visited){
      return {false, result};
    }
    line.visited = true;

    if(line.inst == Inst::ACC){
      result += line.value;
    }

    if(line.inst == Inst::JMP){
      i += line.value;
    }
    else{
      ++i;
    }
  }

  return {true, result};
}

std::int64_t aoc2020solution_8(const char* file_name){
  auto lines = get_lines(file_name);
  std::vector<Line> parsed_lines;
  std::transform(lines.cbegin(), lines.cend(), std::back_inserter(parsed_lines), parse);

  auto result = run_until_looping(parsed_lines);

  // For the solution to to part 1 the program does not terminate.
  assert(!result.first);
  return result.second; 
}

std::int64_t aoc2020solution_8_2(const char* file_name){
  auto lines = get_lines(file_name);
  std::vector<Line> parsed_lines;
  std::transform(lines.cbegin(), lines.cend(), std::back_inserter(parsed_lines), parse);

  for(Line& line: parsed_lines){
    // Try flipping;
    flip(line);
    auto result = run_until_looping(parsed_lines);
    reset_visited(parsed_lines);

    if(result.first){
      return result.second;
    }
    flip(line);
  }

  // Not reached.
  assert(false);
}

void aoc2020_test_8(){
  assert(aoc2020solution_8("./input/2020/day8/test.txt") == 5);
  assert(aoc2020solution_8("./input/2020/day8/day8.txt") == 1475);
  assert(aoc2020solution_8_2("./input/2020/day8/test.txt") == 8);
  assert(aoc2020solution_8_2("./input/2020/day8/day8.txt") == 1270);
}
