#include <bits/stdc++.h>
using namespace std;

bool check(string s, stack<char> st)
{
    for (char x : s)
    {
        if (x == '(' || x == '[' || x == '{')
        {
            st.push(x);
        }
        else
        {
            if (st.empty())
                return 0;
            else if (x == ')' && st.top() == '(')
                st.pop();
            else if (x == ']' && st.top() == '[')
                st.pop();
            else if (x == '}' && st.top() == '{')
                st.pop();
            else
                return 0;
        }
    }
    if (st.empty())
        return 1;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    stack<char> st;
    while (t--)
    {
        string s;
        cin >> s;
        if (check(s, st))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}