#include <unordered_set>
#include <algorithm>
#include <functional>

using words_t = std::vector<std::string>;

bool validate_row(const words_t& words){
    std::unordered_set<std::string> word_set(words.cbegin(), words.cend());
    return word_set.size() == words.size();
}

bool validate_row2(const words_t& words){
    words_t temp{words};
    
    for(std::string& s : temp){
        std::sort(s.begin(), s.end());
    }

    std::unordered_set<std::string> word_set(temp.cbegin(), temp.cend());

    return word_set.size() == words.size();
}

size_t solution_4(const char* file_name, std::function<bool(const words_t&)> func){
    const auto& lines = get_lines(file_name);
    std::vector<std::vector<std::string>> word_groups;
    for(const auto& line : lines){
        word_groups.push_back(parse_line<std::string>(line));
    }
    return std::count_if(word_groups.cbegin(), word_groups.cend(), [func](const std::vector<std::string>& words){return func(words);});
}

void test_4(){
    assert(validate_row(parse_line<std::string>("aa bb cc dd ee")));
    assert(!validate_row(parse_line<std::string>("aa bb cc dd aa")));
    assert(validate_row(parse_line<std::string>("aa bb cc dd aaa")));
}
