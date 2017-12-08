#include <vector>

void print_bins(const std::vector<int>& bins, std::vector<int>::iterator current_it){
    for(auto it=bins.cbegin(); it<bins.cend(); ++it){
        if(it==current_it){
            std::cout << "[" << *it << "]";
        }
        else{
            std::cout << *it;
        }

        if(it != bins.end()-1){
            std::cout << ",";
        }
    }
    std::cout << std::endl;
}

size_t solution_5(std::vector<int> jumps, bool strange){

    auto it{jumps.begin()};

    size_t iterations{1};
    for(;;++iterations){

        int jump{*it};
        
        // If we broke out of the loop we jump out
        if( (it+jump) < jumps.begin() || (it+jump) >= jumps.end()){
            break;
        }
        else{

            if(!strange || (strange && *it < 3)){
                ++(*it);
            }
            else{
                --(*it);
            }
            it+=jump;
        }
    }

    return iterations;
}

void test_5(){
    assert(solution_5({0,3,0,1,-3}, false) == 5);
    assert(solution_5({0,3,0,1,-3}, true) == 10);

    auto lines = get_lines("./input/day5.txt");
    assert(solution_5(read_col<int>(lines,0), false) == 381680);
    assert(solution_5(read_col<int>(lines,0), true) == 29717847);
}
