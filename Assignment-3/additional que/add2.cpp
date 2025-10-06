
#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<int> st, mn;
public:
    Solution() {}

    void push(int x) {
        st.push(x);
        if (mn.empty() || x <= mn.top()) {
            mn.push(x);
        }
    }

    void pop() {
        if (!st.empty()) {
            if (st.top() == mn.top()) {
                mn.pop();
            }
            st.pop();
        }
    }

    int peek() {
        if (!st.empty()) {
            return st.top();
        } else {
            return -1;
        }
    }

    int getMin() {
        if (!mn.empty()) {
            return mn.top();
        } else {
            return -1;
        }
    }
};

