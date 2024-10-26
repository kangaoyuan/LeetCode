#include "../headers.h" // IWYU pragma: keep

const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};

string path;
vector<string> res;

void dfs(string& digits, uint depth){
    if(depth == digits.size()){
        res.push_back(path);
        return;
    }

    string letters = letterMap[digits[depth]-'0'];
    for(uint i = 0; i < letters.size(); ++i){
        path.push_back(letters[i]);
        dfs(digits, depth+1);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    // This is the edge
    // We don't add code to solve the another wrong input.
    if(digits.empty())
        return {};

    dfs(digits, 0);

    return res;
}
