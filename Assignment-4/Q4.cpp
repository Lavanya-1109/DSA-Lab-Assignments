#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s = "a a b c";  
    int freq[256] = {0};
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') {
            continue;
        }
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        if (q.empty()) {
            cout << "(-1) ";
        } else {
            cout << "(" << q.front() << ") ";
        }
    }
}
