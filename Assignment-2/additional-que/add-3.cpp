#include <iostream>
using namespace std;
bool CheckAnagram(string &s1,string &s2) {
    int freq[26]={0};
    if (s1.size()!=s2.size()) {
    	return 0;
	}
    for (int i=0;i<s1.size();i++) freq[s1[i]-'a']++;
    for (int i=0;i<s2.size();i++) freq[s1[i]-'a']--;
    for (int i=0;i<26;i++) {
        if (freq[i]!=0) return 0;
    }
    return 1;
}
int main() {
    string s1="race";
    string s2="care";
    cout<<CheckAnagram(s1,s2);
    return 0;
}