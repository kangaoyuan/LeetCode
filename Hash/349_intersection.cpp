#include "../headers.h" // IWYU pragma: keep

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // set automatically exclusively containing key
    unordered_set<int> set1, set2;

    for (const auto& num : nums1) {
        set1.insert(num);
    }
    for (const auto& num : nums2) {
        set2.insert(num);
    }

    vector<int> intersection;
    for (auto& elem : set1) {
        //if (set2.count(elem)) {
        if (set2.find(elem) != set2.end()) {
            intersection.push_back(elem);
        }
    }

    return intersection;
}
