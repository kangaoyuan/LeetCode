#include "../headers.h" // IWYU pragma: keep

class MyStack {
public:
    queue<int> que;
    MyStack() {}

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int nums = que.size();
        for(int i = 0; i < nums-1; i++){
            int elem = que.front();
            que.pop();
            que.push(elem);
        }
        int rc = que.front();
        que.pop();
        return rc;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};

class MyStack_ {
public:
    queue<int> in_que, out_que;
    MyStack_() {}

    void push(int x) {
        in_que.push(x);
        while (!out_que.empty()) {
            in_que.push(out_que.front());
            out_que.pop();
        }
        swap(in_que, out_que);
    }

    int pop() {
        int rc = out_que.front();
        out_que.pop();
        return rc;
    }

    int top() {
        int rc = out_que.front();
        return rc;
    }

    bool empty() {
        return out_que.empty();
    }
};
