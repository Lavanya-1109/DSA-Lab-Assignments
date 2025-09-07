// reverse string using STACK

#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> st;
    for (char c : str)
    {
        st.push(c);
    }
    string rev = "";
    while (!st.empty())
    {
        rev += st.top();
        st.pop();
    }
    return rev;
}

int main()
{
    string s = "DataStructure";
    cout << "Original: " << s << endl;
    cout << "Reversed: " << reverseString(s) << endl;
    return 0;
}
