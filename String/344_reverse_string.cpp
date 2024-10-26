#include "../headers.h" // IWYU pragma: keep

void reverseString(vector<char>& s) {

    int left = 0, right = s.size();
    //int left = 0, right = s.size()-1;

    // Here, Attention for the pure mid element, we don't operate.
    while(left+1 < right){
    //while(left < right){
        swap(s[left++], s[--right]);
        //swap(s[left++], s[right--]);
    }

    return;
}
