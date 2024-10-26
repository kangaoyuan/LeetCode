#include "../headers.h" // IWYU pragma: keep

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

    unordered_map<int, int> two_val_freq;
    for(const auto& elem1 : nums1)
        for(const auto& elem2 : nums2)
            ++two_val_freq[elem1 + elem2];

    int res = 0;
    for(const auto& elem3 : nums3)
        for(const auto& elem4 : nums4){
            int val = -(elem3 + elem4);
            if(two_val_freq[val]){
                res += two_val_freq[val];
            }
        }

    return res;
}
