class MinStack {
    stack<long long> st;
    long long minElement;

public:
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minElement = val;
        } else {
            if (val >= minElement) {
                st.push(val);
            } else {
                st.push(2LL * val - minElement); // encode
                minElement = val;
            }
        }
    }

    void pop() {
        if (st.top() >= minElement) {
            st.pop();
        } else {
            // it's an encoded value, restore previous min
            minElement = 2 * minElement - st.top();
            st.pop();
        }
    }

    int top() {
        if (st.top() >= minElement) return st.top();
        else return minElement; // actual top value is the current min
    }

    int getMin() {
        return minElement;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */