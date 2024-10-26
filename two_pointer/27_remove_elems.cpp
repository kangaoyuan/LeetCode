#include "../headers.h" // IWYU pragma: keep

/*
// Too showy, but can provide much controls.
int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for(uint read =0, write = 0; read < nums.size(); read++) {
        if(nums[read] != val){
            while(read < nums.size() && nums[read] != val){
                cnt++;
                nums[write++] = nums[read++];
            }
        }
    }
    return cnt;
}
*/

int removeElement(vector<int>& nums, int val) {
    uint read =0, write = 0;
    while(read < nums.size()) {
        if(nums[read] != val)
            nums[write++] = nums[read];
        read++;
    }
    return write;
}
