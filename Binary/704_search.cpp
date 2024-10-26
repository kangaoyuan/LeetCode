#include "../headers.h" // IWYU pragma: keep

int search(vector<int>& nums, int target) {
/*
 *    uint left = 0, right = nums.size();
 *
 *    // [) interval
 *    while(left < right) {
 *        // Avoid overflow.
 *        int mid = left + (right - left)/2;
 *        if(nums[mid] < target)
 *            left = mid + 1;
 *        else
 *            right = mid;
 *    }
 *
 *    assert(left == right);
 *    if(right == nums.size() || nums[left] != target)
 *        return -1;
 *    else
 *        return left;
 */

    uint left = 0, right = nums.size();

        // [) interval
        while (left < right) {
            // Avoid overflow.
            int mid = left + (right - left) / 2;
            // Ensure
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        assert(left == right);
        if (right == 0 || nums[right-1] != target)
            return -1;
        else
            return right-1;
}
