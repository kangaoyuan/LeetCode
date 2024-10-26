#include "../headers.h" // IWYU pragma: keep

int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX;
    int left = 0, right = 0, sum = 0, len = nums.size();
    while(right < len){
        sum += nums[right];
        if(sum >= target){
            while(sum >= target){
                sum -= nums[left++];
            }
            if(right-left+2 < res)
                res = right-left+2;
        }
    }
    if(res == INT_MAX)
        return 0;
    return res;
}
