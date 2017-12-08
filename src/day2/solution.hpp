#include <algorithm>
#include <functional>
#include "../file_reader.hpp"

using row_t = const std::vector<size_t>&;

size_t diff_row(row_t row){
    auto pair = std::minmax_element(row.cbegin(), row.cend());
    return *pair.second - *pair.first;
}

size_t divisible(row_t row){
    // brute force!
    for(auto it1=row.begin();it1<row.end();++it1){
        // Since we find the min and max, no nee to
        // Start back from the beginning of the line
        for(auto it2=it1;it2<row.end();++it2){
            if(it1 != it2){
                auto big = std::max(*it1, *it2);
                auto small = std::min(*it1, *it2);
                if(big%small == 0){
                    return big/small;
                }
            }
        }
    }

    return 0;
}

size_t solution_2(const std::vector<std::string>& rows, std::function<size_t(row_t)> func){

    size_t checksum{0};
    
    for(const auto& row : rows){
        checksum += func(parse_line<size_t>(row));
    }

    return checksum;
}

void test_2(){
    assert(diff_row(parse_line<size_t>("5 1 9 5")) == 8);
    assert(diff_row(parse_line<size_t>("7 5 3")) == 4);
    assert(diff_row(parse_line<size_t>("2 4 6 8")) == 6);

    assert(divisible(parse_line<size_t>("5 9 2 8")) == 4);
    assert(divisible(parse_line<size_t>("9 4 7 3")) == 3);
    assert(divisible(parse_line<size_t>("3 8 6 5")) == 2);
}
