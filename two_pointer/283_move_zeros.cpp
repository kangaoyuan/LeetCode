#include "../headers.h" // IWYU pragma: keep

void moveZeroes(vector<int>& nums) {
    int write = 0, read = 0, len = nums.size();
    while(write < len){
        if(nums[read] != 0){
            nums[write++] = nums[read++];
        } else {
            read++;
        }
    }
    for(int i = read; i < len; ++i){
        nums[i] = 0;
    }
}

// It's error, which can't keep the relatively location.
void moveZeroes_(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while(left <= right){
        while(nums[left] != 0)
            left++;
        while(nums[right] == 0)
            right--;
        swap(nums[left], nums[right]);
    }
}

void moveZeroes__(vector<int>& nums) {
    int slow = 0, fast = 0, len = nums.size();
    while(fast < len){
        if(nums[fast]){
            swap(nums[slow++], nums[fast++]);
        }
    }
}
