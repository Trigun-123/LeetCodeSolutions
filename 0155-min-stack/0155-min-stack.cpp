class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } 
        else if (val >= mini) {
            st.push(val);
        } 
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;
        long long t = st.top();
        st.pop();
        if (t < mini) {
            mini = 2LL * mini - t;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long t = st.top();
        if (t < mini) return (int)mini;
        return (int)t;
    }

    int getMin() {
        return (int)mini;
    }
};
