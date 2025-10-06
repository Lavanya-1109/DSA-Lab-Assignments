#include <iostream>
#include <queue>
using namespace std;

int main() {
    int arr[] = {7, 9, 11, 20, 5, 4};
    int n = 6;

    queue<int> q;
    for (int i = 0; i < n; i++) q.push(arr[i]);

    int half = n / 2;
    queue<int> first;
    for (int i = 0; i < half; i++) {
        first.push(q.front());
        q.pop();
    }

    while (!first.empty()) {
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
