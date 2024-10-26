#include "../headers.h" // IWYU pragma: keep

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int         len = temperatures.size();
    stack<int>  stk;
    vector<int> res(len);

    for (int i = 0; i < len; ++i) {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            res[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }

    return res;
}

/*
 *vector<int> dailyTemperatures(vector<int>& temperatures) {
 *    int len = temperatures.size();
 *    stack<int> stk;
 *    vector<int> res(len);
 *
 *    for(int i = len-1; i >=0; i--) {
 *        while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]){
 *            stk.pop();
 *        }
 *        if(!stk.empty())
 *            res[i] = stk.top() - i;
 *        stk.push(i);
 *    }
 *
 *    return res;
 *}
 *
 */

/*
 *vector<int> dailyTemperatures(vector<int>& temperatures) {
 *    int         size = temperatures.size();
 *    stack<int>  st;
 *    vector<int> res(size);
 *
 *    for (int i = 0; i < size; ++i) {
 *        if (st.empty() || temperatures[st.top()] >= temperatures[i]) {
 *            st.push(i);
 *        } else {
 *            while (!st.empty() &&
 *                   temperatures[st.top()] < temperatures[i]) {
 *                int index = st.top();
 *                res[index] = i - index;
 *                st.pop();
 *            }
 *            st.push(i);
 *        }
 *    }
 *
 *    while (!st.empty()) {
 *        int index = st.top();
 *        res[index] = 0;
 *        st.pop();
 *    }
 *
 *    return res;
 *}
 */
