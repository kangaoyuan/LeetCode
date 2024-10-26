#include "../headers.h" // IWYU pragma: keep


int lower_bound(vector<int> nums, int target){
    int left = 0, right = nums.size();

    while(left < right){
        int mid = left + (right - left)/2;
        if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int start = lower_bound(nums, target);
    if((uint)start == nums.size() || nums[start] != target){
        return {-1, -1};
    }
    int end = lower_bound(nums, target+1) -1;
    return {start, end};
}
