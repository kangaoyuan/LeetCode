#include "../headers.h" // IWYU pragma: keep

long edge_len;

bool backtrace(vector<int>& matchsticks, uint index, vector<long>& four_side){
    if(index == matchsticks.size()){
        for(int i = 0; i < 3; ++i){
            if(four_side[i] != edge_len)
                return false;
        }
        return true;
    }

    int elem = matchsticks[index];
    for (int i = 0; i < 4; ++i) {
        if(four_side[i] + elem > edge_len)
            continue;
        if(i > 0 && four_side[i] == four_side[i-1])
            continue;

        four_side[i] += elem;
        if(backtrace(matchsticks, index+1, four_side))
            return true;
        four_side[i] -= elem;
    }

    return false;
}

bool makesquare(vector<int>& matchsticks) {
    long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    edge_len = sum / 4;
    if(sum % 4)
        return false;

    sort(matchsticks.begin(), matchsticks.end());
    vector<long> four_side(4);
    return backtrace(matchsticks, 0, four_side);
}
