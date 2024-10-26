#include "../headers.h" // IWYU pragma: keep

bool isHappy(int n) {
    vector<int> digs;
    unordered_set<int> stages;

    uint64_t val = n;
    while (val != 1) {
        digs.clear();
        while (val) {
            digs.push_back(val % 10);
            val /= 10;
        }

        for (const auto& elem : digs) {
            val += elem * elem;
        }
        if(stages.find(val) != stages.end())
            return false;

        stages.insert(val);
    }

    return true;
}
