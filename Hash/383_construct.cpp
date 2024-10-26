#include "../headers.h" // IWYU pragma: keep

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<int, int> letters;
    for(const auto& elem : magazine){
        letters[elem]++;
    }
    for(const auto& elem : ransomNote){
        if(!letters[elem])
            return false;
        letters[elem]--;
    }
    return true;
}
