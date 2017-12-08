#include <vector>

void print_bins(const std::vector<size_t>& bins, std::vector<size_t>::iterator current_it){
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
