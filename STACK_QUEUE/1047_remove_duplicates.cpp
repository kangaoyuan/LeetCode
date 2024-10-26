#include "../headers.h" // IWYU pragma: keep

string removeDuplicates(string s) {
    string res;

    /*
     *for (const auto& elem : s) {
     *    if (res.empty() || elem != res.back())
     *        res.push_back(elem);
     *    else
     *        res.pop_back();
     *}
     */

    for (const auto& elem : s) {
        if (res.empty()) {
            res.push_back(elem);
        } else {
            if (res.back() == elem) {
                res.pop_back();
            } else {
                res.push_back(elem);
            }
        }
    }

    return res;
}
