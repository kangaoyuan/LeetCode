#include "../headers.h" // IWYU pragma: keep

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> fre;
    for(const auto& elem : nums)
        fre[elem]++;

    auto cmp = [&](int a, int b){
        return fre[a] > fre[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> min_heap(cmp);

/*
 *    auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
 *        return p1.second > p2.second;
 *    };
 *
 *    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
 *        que(cmp);
 */

    for(const auto& elem : fre){
        min_heap.push(elem.first);
        if(min_heap.size() > (uint)k){
            min_heap.pop();
        }
    }

    vector<int> res;
    while(!min_heap.empty()){
        res.push_back(min_heap.top());
        min_heap.pop();
    }

    return res;
}
