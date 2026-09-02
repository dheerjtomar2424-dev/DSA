class MinStack {
    vector<int> st;
    vector<int> mn;

public:
    MinStack() {}

    void push(int val) {
        st.push_back(val);

        if (mn.empty())
            mn.push_back(val);
        else
            mn.push_back(min(val, mn.back()));
    }

    void pop() {
        st.pop_back();
        mn.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return mn.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */