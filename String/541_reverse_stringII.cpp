#include "../headers.h" // IWYU pragma: keep

string reverseStr(string s, int k) {

    // Here k must be postive
    uint i = 0;
    for(i = 0; i + 2*k <= s.size(); i += 2*k){
        int left = i, right = i+k-1;
        while(left < right){
            swap(s[left++], s[right--]);
        }
    }

    uint left = i, right = i;
    if(left + k <= s.size())
        right = i+k-1;
    else
        right = s.size()-1;

    while(left < right)
        swap(s[left++], s[right--]);

    return s;
}
