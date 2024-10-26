#include "../headers.h" // IWYU pragma: keep

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    vector<int> res;

    for(int i = 0; i < (int)nums.size(); ++i){
        while (que.size() && nums[i] > nums[que.back()])
            que.pop_back();

        que.push_back(i);

        //if (i >= k && (i - k) == que.front())
        if (i - k == que.front())
            que.pop_front();

        if (i >= k-1)
            res.push_back(nums[que.front()]);
    }

    return res;
}

