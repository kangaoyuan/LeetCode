#include "../headers.h" // IWYU pragma: keep

vector<string> res;

bool is_valid(string& s, uint start_index, uint end_index) {
    if (end_index == start_index || end_index - start_index > 3)
        return false;
    if (s[start_index] == '0' && end_index - start_index > 1)
        return false;
    string str(s.begin() + start_index, s.begin() + end_index);
    int    val = stoi(str);
    if (val >= 0 && val < 256)
        return true;
    return false;
}

void backtrace(string& s, uint start_index, uint depth) {
    if (depth == 3) {
        if (is_valid(s, start_index, s.size())) {
            res.push_back(s);
            return;
        }
    }

    for (uint i = start_index; i < s.size(); ++i) {
        if (is_valid(s, start_index, i + 1)) {
            s.insert(s.begin() + i + 1, '.');
            backtrace(s, i + 2, depth + 1);
            s.erase(s.begin() + i + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    backtrace(s, 0, 0);
    return res;
}
