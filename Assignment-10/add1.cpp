#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 4, 1};
    int n = 5;

    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++)
        mp[arr[i]]++;

    int maxFreq = 0;
    int ans = -1;

    for(auto p : mp) {
        if(p.second > maxFreq) {
            maxFreq = p.second;
            ans = p.first;
        }
        else if(p.second == maxFreq) {
            ans = max(ans, p.first);
        }
    }

    cout << ans;
    return 0;
}
