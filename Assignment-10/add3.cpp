#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int a[] = {1, 7, 1};
    int b[] = {7, 7, 1};

    int n = 3;

    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++)
        mp[a[i]]++;

    for(int i = 0; i < n; i++)
        mp[b[i]]--;

    for(auto p : mp) {
        if(p.second != 0) {
            cout << "false";
            return 0;
        }
    }

    cout << "true";
    return 0;
}
