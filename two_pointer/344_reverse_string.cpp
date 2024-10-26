#include "../headers.h" // IWYU pragma: keep

void reverseString_(vector<char>& s) {
    int left = 0, right = s.size();

    while(left + 1 < right){
        swap(s[left++], s[--right]);
    }

    return;
}

void reverseString__(vector<char>& s) {
    int left = 0, right = s.size()-1;

    while(left < right){
        swap(s[left++], s[right--]);
    }

    return;
}
