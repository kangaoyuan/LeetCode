#include "../headers.h" // IWYU pragma: keep

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    set<string> operators = {"+", "-", "*", "/"};
    for(const auto& elem : tokens) {
        //if (elem == "+" || elem == "-" || elem == "*" || elem == "/") {
        if(operators.find(elem) != operators.end()){
            int res = 0;
            int operand2 = stk.top();
            stk.pop();
            int operand1 = stk.top();
            stk.pop();

            if(elem == "+")
                res = operand1 + operand2;
            if(elem == "-")
                res = operand1 - operand2;
            if(elem == "*")
                res = operand1 * operand2;
            if(elem == "/")
                res = operand1 / operand2;

            stk.push(res);
        } else {
            int rc = stoi(elem);
            stk.push(rc);
        }
    }

    return stk.top();
}
