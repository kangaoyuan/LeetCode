#include <climits>
#include <string>
#include <unordered_map>

std::string minWindow(std::string s, std::string t) {
    std::string res;
    std::unordered_map<char, int> need, windows;
    int left = 0, right = 0, valid = 0, start = 0, len = INT_MAX;
    for(char c : t){
        need[c]++;
    }

    while(right < s.size()){
        char c = s[right++];
        if(need.count(c)){
            windows[c]++;
            if(windows[c] == need[c])
                valid++;
        }

        while(left < right && valid == need.size()){
            if(right - left < len){
                start = left;
                len = right -left;
            }

            char c = s[left++];

            if(need.count(c)){
                if(windows[c] == need[c])
                    valid--;
                windows[c]--;
            }
        }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
}

