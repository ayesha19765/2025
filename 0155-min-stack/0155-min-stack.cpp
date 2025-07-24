class MinStack {
public:
    stack<long long> st;
    int mini;
    MinStack() {
        mini = -1;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            mini = val;
        }else{
            st.push(long(val) - mini);
            mini = min(mini, val);
        }
    }
    
    void pop() {
        if(st.top() < 0) // minimum element till now
            mini = mini - st.top();
        st.pop();
    }
    
    int top() {
        if(st.top() < 0) 
            return mini;
        return mini + st.top();
    }
    
    int getMin() {
        return mini;
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