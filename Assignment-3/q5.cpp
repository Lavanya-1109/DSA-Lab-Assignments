#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> st;
    for (char c : exp)
    {
        if (isdigit(c))
            st.push(c - '0');
        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            switch (c)
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp = "231*+9-"; // Example
    cout << "Postfix: " << exp << endl;
    cout << "Evaluated Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
