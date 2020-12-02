#include <set>
#include <algorithm>
#include <iostream>

auto solution_6(std::vector<size_t> bins){

    std::pair<size_t, size_t> result{0,0};

    // Don't feel like hashing!
    std::set<std::vector<size_t>> seen_states;
    seen_states.insert(bins);

    bool looped = false;

    size_t iterations{1};
    for(;;++iterations){

        // Find the largest bin
        auto largest_it = std::max_element(bins.begin(), bins.end());
        
        // Keep track of how many bins we have to distribute
        size_t to_distribute{*largest_it};

        // Clear the largest bin
        *largest_it = 0;

        // Start iterating
        auto it = largest_it;

        auto advance_it = [&bins,&it](){
            if(it+1 == bins.end()){
                it = bins.begin();
            }
            else{
                ++it;
            }
        };
        
        for(size_t i=0;i<to_distribute;++i){
            advance_it();
            (*it)++;
        }

        if(!seen_states.insert(bins).second){
            if(!looped){
                seen_states.clear();
                seen_states.insert(bins);

                result.first = iterations;

                iterations = 0;
                looped = true;
            }
            else{
                result.second = iterations;
                break;
            }
        }
    }

    return result;
}

void aoc2017_test_6(){
    auto result = solution_6(parse_line<size_t>("5   1   10  0   1   7   13  14  3   12  8   10  7   12  0   6"));
    assert(result.first == 5042);
    assert(result.second == 1086);
}
