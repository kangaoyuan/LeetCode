#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> window;
    int left = 0, right = 0, res = 0;
    while(right < s.size()){
        char c = s[right++];
        window[c]++;

        while(window[c] > 1){
            char c = s[left++];
            window[c]--;
        }
        res = std::max(res, right-left);
    }
    return res;
}
