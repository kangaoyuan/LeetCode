#include "../headers.h" // IWYU pragma: keep

bool isAnagram(string s, string t) {
    int alpha[256] = {0};

    for(const auto& elem : s)
        alpha[(uint8_t)elem]++;

    for(const auto& elem : t)
        alpha[(uint8_t)elem]--;

    for(const auto& elem: alpha)
        if(elem)
            return false;

    return true;
}
