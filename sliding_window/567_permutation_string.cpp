#include <string>
#include <unordered_map>

bool checkInclusion(std::string s1, std::string s2)
{
    int left = 0, right = 0, valid = 0;
    std::unordered_map<char, int> need, window;
    for (char c : s1)
        need[c]++;

    while(right < s2.size()){
        char c = s2[right++];
        if(need.count(c)){
            window[c]++;
            if(window[c] == need[c])
                valid++;
        }

        while(right - left >= s1.size()){
            if(valid == need.size())
                return true;
            char c = s2[left++];
            if(need.count(c)){
                if(window[c] == need[c])
                    valid--;
                window[c]--;
            }
        }
    }
    return false;
}
