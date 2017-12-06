#include <cmath>
#include <map>

size_t solution_3(size_t index){

    // First of all find the size of the cube one down
    size_t one_down = std::sqrt(index);

    // Subtract 1 because the spiral starts on the tile above the one where it ends
    --index;

    // The size of our own square
    size_t side{one_down+2};

    // Find out your distance to an edge
    size_t distance = (index%side);

    // Find your distance to the midle
    distance = std::abs((long(side/2)+1) - long(distance));
    
    // Sub one because the spiral starts at the step over the actual last step
    // Add half the side because that always need to be stepped over
    return distance-1 + side/2;
}

enum class direction: size_t{
    RIGHT=0,
    UP=1,
    LEFT=2,
    DOWN=3,
};

size_t solution_3_2(size_t value){

    // Creating a hash function? Ain't nobody got time for that!
    std::map<std::pair<int, int>, size_t> grid;
    grid[{0,0}] = 1; // Initial cell
    
    int min_x{0};
    int max_x{0};

    int min_y{0};
    int max_y{0};

    int current_x{0};
    int current_y{0};
    
    // State starts with going right
    direction current_dir{direction::RIGHT};
    
    // We are spiraling so alternate directions
    auto change_dir = [&](){
        size_t val{static_cast<size_t>(current_dir)};
        ++val;

        val %= 4;
        current_dir = static_cast<direction>(val);
    };

    auto update_grid = [&](){
        size_t sum{0};
        
        // Check all neighbours
        for(auto move : std::vector<std::pair<int,int>>{{1,-1}, {1,0} , {1,1}, {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}}){
            sum+=grid[{current_x+move.first,current_y+move.second}];    
        }

        grid[{current_x, current_y}] = sum;

        if(sum > value){
            return sum;
        }

        return size_t{0};
    };
    
    size_t i{0}; 
    for(;;++i){

        if(current_dir==direction::RIGHT){
            while(current_x <= max_x){
                ++current_x;
                auto sum{update_grid()};
                if(sum){
                    return sum;
                } 
            }
            change_dir();
            max_x = current_x;
            continue;
        }
        else if(current_dir==direction::LEFT){
            while(current_x >= min_x){
                --current_x;
                auto sum{update_grid()};
                if(sum){
                    return sum;
                } 
            }
            min_x = current_x;
            change_dir();
            continue;
        }
        else if(current_dir==direction::UP){
            while(current_y <= max_y){
                ++current_y;
                auto sum{update_grid()};
                if(sum){
                    return sum;
                } 
            }
            max_y = current_y;
            change_dir();
            continue;
        }
        else if(current_dir==direction::DOWN){
            while(current_y >= min_y){
                --current_y;
                auto sum{update_grid()};
                if(sum){
                    return sum;
                } 
            }
            min_y = current_y;
            change_dir();
            continue;
        }
    }
    
    return 0;
}

void test_3(){
    assert(solution_3(12) == 3);
    assert(solution_3(23) == 2);
    assert(solution_3(1024) == 31);
    assert(solution_3_2(265149) == 266330);
}

