#include "../headers.h" // IWYU pragma: keep

void remove_extra_space(string& s){
    uint slow = 0, fast = 0;
    while(fast < s.size()){
        if(s[fast] != ' '){
            if(slow != 0){
                s[slow++] = ' ';
            }
            while(fast < s.size() && s[fast] != ' '){
                s[slow++] = s[fast++];
            }
        } else{
            fast++;
        }
    }
    // It's important for another method to use such as reverse().
    s.resize(slow);
}

string reverseWords(string s) {
    remove_extra_space(s);
    reverse(s.begin(), s.end());

    uint left = 0, right = 0;
    while(right < s.size()){
        if(s[right] == ' '){
            reverse(s.begin()+left, s.begin()+right);
            left = right+1;
        }
        right++;
    }
    //reverse(s.begin()+left, s.end());
    reverse(s.begin()+left, s.begin()+right);

    return s;
}
