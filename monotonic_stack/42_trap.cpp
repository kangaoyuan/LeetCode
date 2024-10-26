#include "../headers.h" // IWYU pragma: keep

int trap(vector<int>& height){
    stack<int> stk;
    int res =0, n = height.size();

    for(int i = 0; i < n; ++i){
        while(!stk.empty() && height[i] > height[stk.top()]) {
            int bottom_h = height[stk.top()];
            stk.pop();
            if(!stk.empty()){
                int left = stk.top();
                int delta_h = min(height[left], height[i]) - bottom_h;
                res += delta_h * (i - left - 1);
            }
        }
        stk.push(i);
    }
    return res;
}



