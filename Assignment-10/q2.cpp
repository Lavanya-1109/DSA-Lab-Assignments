#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};

    unordered_set<int> st;

    for(int x : A)
        st.insert(x);

    cout << "Common elements: ";
    for(int y : B) {
        if(st.find(y) != st.end()) {
            cout << y << " ";
        }
    }
    return 0;
}
