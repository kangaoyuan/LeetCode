#include "../headers.h" // IWYU pragma: keep

void pop_action(stack<int>& stk, int elem, bool& res){
    if (stk.empty()) {
        res = false;
        return;
    }
    int rc = stk.top();
    stk.pop();
    if (rc != elem) {
        res = false;
    }
    return;
}

bool isValid(string s) {
    stack<int> stk;
    bool res = true;

    for(uint i = 0; i < s.size(); ++i){
        int elem = s[i];
        switch(elem){
        case '(':
            stk.push(')');
            break;
        case '[':
            stk.push(']');
            break;
        case '{':
            stk.push('}');
            break;
        case ')':
            pop_action(stk, ')', res);
            break;
        case ']':
            pop_action(stk, ']', res);
            break;
        case '}':
            pop_action(stk, '}', res);
            break;
        }
        if(!res)
            break;
    }
    return res && !stk.size();
}



bool isValid_(string s) {
    stack<int>    st;
    set<int>      vals = {'(', '[', '{'};
    map<int, int> matchs = {{')', '('}, {']', '['}, {'}', '{'}};
    for (const auto& elem : s) {
        if (vals.find(elem) != vals.end()) {
            st.push(elem);
        } else {
            if (st.empty())
                return false;
            else {
                if (matchs[elem] != st.top())
                    return false;
                st.pop();
            }
        }
    }
    return st.empty();
}
