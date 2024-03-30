#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> findAnagrams(std::string s, std::string p) {
    int left = 0, right = 0, valid = 0;
    std::vector<int> res;
    std::unordered_map<char, int> need, window;
    for(char c: p)
        need[c]++;

    while(right < s.size()){
        char c = s[right++];
        if(need.count(c)){
            window[c]++;
            if(window[c] == need[c])
                valid++;
        }

        //while(left < right && right - left >= p.size()){
        while(right - left >= p.size()){
            if(valid == need.size()){
                res.push_back(left);
            }
            char c = s[left++];
            if(need.count(c)){
                if(window[c] == need[c])
                    valid--;
                window[c]--;
            }
        }
    }

    return res;
}
