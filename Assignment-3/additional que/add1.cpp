#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = NSE(arr);

    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
