#include "../headers.h" // IWYU pragma: keep

int trap(vector<int>& height) {
    int size = height.size();
    int left_max = -1, right_max = -1;
    vector<int> left_height(size), right_height(size);

    for(int i = 0; i < size; ++i){
        if(height[i] > left_max){
            left_max = height[i];
        }
        left_height[i] = left_max;
    }

    for(int i = size-1; i >= 0; --i){
        if(height[i] > right_max){
            right_max = height[i];
        }
        right_height[i] = right_max;
    }

    int res = 0;
    for(int i = 0; i < size; ++i){
        res += min(left_height[i], right_height[i]) - height[i];
    }

    return res;
}

