#include "../headers.h" // IWYU pragma: keep

// aaba
bool is_palindrome(string s, uint start, uint end){
    end--;
    while(start <= end){
    //while(start < end){
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void backtrace(string s, uint start, uint nums, vector<string> path, vector<vector<string>>& res){
    if(nums == s.size()){
        res.push_back(path);
        return;
    }

    backtrace(s, start, nums+1, path, res);

    if(is_palindrome(s, start, nums+1)){
        path.push_back(string(s.begin()+start, s.begin()+nums+1));
        backtrace(s, nums+1, nums+1, path, res);
    }
}

vector<vector<string>> partition(string s) {
    vector<string> path;
    vector<vector<string>> res;
    backtrace(s, 0, 0, path, res);
    return res;
}
