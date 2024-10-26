#include "../headers.h" // IWYU pragma: keep

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> res;
/*
 *    int max = INT_MIN;
 *
 *    for(const auto& elem : candies){
 *        if(elem > max)
 *            max = elem;
 *    }
 */
    int max = ranges::max(candies);

    for(const auto& elem : candies){
        if(elem - max + extraCandies >= 0)
            res.push_back(true);
        else
            res.push_back(false);
    }

    return res;
}

