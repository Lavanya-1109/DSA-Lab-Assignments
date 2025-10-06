#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    stack<int> st;
    int need = 1;
    for (int i = 0; i < N; i++) {
        st.push(A[i]);
        while (!st.empty() && st.top() == need) {
            st.pop();
            need++;
        }
    }
    if (st.empty()) {
        cout << "YES"<<endl;
    } else {
        cout << "NO\n"<<endl;
    }
    return 0;
}
