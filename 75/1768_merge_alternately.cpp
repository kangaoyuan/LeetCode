#include "../headers.h" // IWYU pragma: keep

string mergeAlternately(string word1, string word2) {
    string res;
    int left1 = 0, right1 = word1.size();
    int left2 = 0, right2 = word2.size();
    while (left1 < right1 && left2 < right2) {
        res.push_back(word1[left1++]);
        res.push_back(word2[left2++]);
    }

    while(left1 < right1){
        res.push_back(word1[left1++]);
    }
    while(left2 < right2){
        res.push_back(word2[left2++]);
    }

    return res;
}

string mergeAlternately_(string word1, string word2) {
    string res;
    int left1 = 0, right1 = word1.size();
    int left2 = 0, right2 = word2.size();
    int right = min(right1, right2);

    for(int i = 0; i < right; ++i){
        res.push_back(word1[left1++]);
        res.push_back(word2[left2++]);
    }

    if(left1 == right1){
        while(left2 < right2)
            res.push_back(word2[left2++]);
    } else {
        while(left1 < right1)
            res.push_back(word1[left1++]);
    }

    return res;
}

string mergeAlternately__(string word1, string word2) {
    string res;
    int    num1 = word1.size(), num2 = word2.size();

    for (int i = 0; i < num1 || i < num2; i++) {
        if (i < num1) {
            res += word1[i];
        }
        if (i < num2) {
            res += word2[i];
        }
    }

    return res;
}
