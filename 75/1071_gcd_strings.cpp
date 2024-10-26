#include "../headers.h" // IWYU pragma: keep

string gcdOfStrings(string str1, string str2) {
    string res;
    if(str1.size() <= str2.size()){
        uint i = 0;
        for( ; i < str1.size(); ++i){
            if(str1[i] != str2[i]){
                break;
            }
        }
        res = string(str1.begin(), str1.begin()+i);
    } else {
        uint i = 0;
        for( ; i < str2.size(); ++i){
            if(str2[i] != str1[i]){
                break;
            }
        }
        res = string(str2.begin(), str2.begin()+i);
    }

    return res;
}
