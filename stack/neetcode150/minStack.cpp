#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> s;     // main stack
    stack<int> mins;  // stack to store minimum values

    // Constructor
    MinStack() {}

    // Push element onto stack
    void push(int val) {
        s.push(val);

        // If mins stack is not empty, store the minimum till now
        if (!mins.empty()) {
            val = min(val, mins.top());
        }
        mins.push(val);
    }

    // Remove top element
    void pop() {
        if (!s.empty()) {
            s.pop();
            mins.pop();
        }
    }

    // Get top element
    int top() {
        return s.top();
    }

    // Get minimum element
    int getMin() {
        return mins.top();
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top element: " << st.top() << endl;       // Expected: 2
    cout << "Minimum: " << st.getMin() << endl;        // Expected: 2

    st.pop();  // removes 2

    cout << "Top element after pop: " << st.top() << endl;  // Expected: 7
    cout << "Minimum after pop: " << st.getMin() << endl;   // Expected: 3

    st.pop();  // removes 7

    cout << "Top element: " << st.top() << endl;       // Expected: 3
    cout << "Minimum: " << st.getMin() << endl;        // Expected: 3

    return 0;
}
