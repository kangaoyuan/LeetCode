#include "../headers.h" // IWYU pragma: keep

class MyQueue{
    std::stack<int> in_stack;
    std::stack<int> out_stack;

    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {

        int res = peek();

        // error code aggregation.
        if(res == -1)
            return -1;

        out_stack.pop();
        return res;

    }

    int peek() {

        if(empty())
            // error code.
            return -1;

        if(out_stack.empty()){
            while(!in_stack.empty()){
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }

        return out_stack.top();
    }

    bool size() {
        return in_stack.size() + out_stack.size();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};
