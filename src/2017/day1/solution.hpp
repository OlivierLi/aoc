#include <cassert>
#include <vector>
#include <string>

int char_to_int(char c){
    if(!(c >= '0' && c <= '9')){
        std::cout << "Invalid char!:" << c << std::endl;
        assert(false);
    }

    return c-'0';
}

size_t solution_1(const std::string& line){
    size_t count{0};
    auto it{line.begin()};
    char previous{*it++};

    // Special case for circular list
    if(line.front() == line.back()){
        count+=char_to_int(line.front());
    }

    for(;it<line.end();++it){
        char current{*it};

        if(current == previous){
            count+=char_to_int(current);
        }

        previous = current;
    }

    return count;
}

void aoc2017_test_1(){
    assert(solution_1("1122") == 3);
    assert(solution_1("1111") == 4);
    assert(solution_1("1234") == 0);
    assert(solution_1("91212129") == 9);
}

size_t solution_1_2(const std::string& line){
    size_t count{0};
    size_t skip(line.size()/2);

    for(size_t i{0};i<line.size();++i){
        if(line[i] == line[(i+skip)%line.size()]){
            count+=char_to_int(line[i]);
        }
    }

    return count;
}

void aoc2017_test_1_2(){
    assert(solution_1_2("1212") == 6);
    assert(solution_1_2("1221") == 0);
    assert(solution_1_2("123425") == 4);
    assert(solution_1_2("123123") == 12);
    assert(solution_1_2("12131415") == 4);
}
