#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello", s2 = "World";

    
    cout << "Concatenation: " << s1 + s2 << endl;

    
    string rev = s1;
    reverse(rev.begin(), rev.end());
    cout << "Reverse: " << rev << endl;

    
    string noVowels = "";
    for (char c : s1) {
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U') {
            noVowels += c;
        }
    }
    cout << "Without vowels: " << noVowels << endl;

    
    string sorted = s1;
    sort(sorted.begin(), sorted.end());
    cout << "Sorted: " << sorted << endl;

    
    string lower = s1;
    for (char &c : lower) c = tolower(c);
    cout << "Lowercase: " << lower << endl;

    return 0;
}
