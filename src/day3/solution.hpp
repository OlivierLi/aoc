#include <cmath>

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

void test_3(){
    assert(solution_3(12) == 3);
    assert(solution_3(23) == 2);
    assert(solution_3(1024) == 31);
}
