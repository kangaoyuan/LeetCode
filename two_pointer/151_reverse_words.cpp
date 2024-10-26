#include "../headers.h" // IWYU pragma: keep

// [) interval.
void reverse_string(string& s, int start, int end){
    while(start+1 < end)
        swap(s[start++], s[--end]);
}

void remove_extra_space(string& s){
    uint slow = 0, fast = 0;
    while(fast < s.size()){
        if(s[fast] != ' '){
            if(slow != 0)
                s[slow++] = ' ';
            while(fast < s.size() && s[fast] != ' ')
                s[slow++] = s[fast++];
        }
        fast++;
    }
    s.resize(slow);
}

string reverseWords(string s) {
    remove_extra_space(s);
    reverse_string(s, 0, s.size());

    int start = 0;
    for(uint i = 0; i < s.size(); ++i){
        if(s[i] == ' '){
            reverse_string(s, start, i);
            start = i+1;
        }
    }
    reverse_string(s, start, s.size());

    return s;
}



/*
// [] interval
void reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void removeExtraSpaces(string& s) {
    int slow = 0;
    for (uint i = 0; i < s.size(); ++i) {
        // It's better to control the fast pointer to do the operation.
        if (s[i] != ' ') {
            if (slow != 0)
                s[slow++] = ' ';

            while (i < s.size() && s[i] != ' ')
                s[slow++] = s[i++];
        }
    }
    s.resize(slow);
}

string reverseWords(string s) {
    removeExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    int start = 0;
    for (uint i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }
    reverse(s, start, s.size() - 1);
    return s;
}
*/
