#include "../headers.h" // IWYU pragma: keep

bool repeatedSubstringPattern(string s) {
    uint left = 0, right = 0;

    while(right < s.size()) {
        bool flag = true;
        int diff = 1, len = right - left + 1;
        while(right + len < s.size() && left <= right){
            if(s[left+diff] != s[right+diff]){
                flag = false;
                break;
            }
        }
        if(right + len == s.size() && flag)
            return true;
        right++;
    }

    return false;
}
