class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {
        if(st.empty()) {
            mini = value;
            st.push(value);
        }
        else {
            if(value > mini) {
                st.push(value);
            }
            else {
                st.push(2LL * value - mini);
                mini = value;
            }
        }
    }

    void pop() {
        if(st.empty()) return;

        long long curr = st.top();
        st.pop();

        if(curr < mini) {
            mini = 2LL * mini - curr;
        }
    }

    int top() {
        if(st.top() < mini) {
            return (int)mini;
        }
        return (int)st.top();
    }

    int getMin() {
        return (int)mini;
    }
};