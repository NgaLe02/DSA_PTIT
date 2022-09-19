#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')' || s[i] == ']')
        {
            if (st.empty())
                return 0;
            else if (s[i] == ')' && st.top() == '(')
                st.pop();
            else if (s[i] == ']' && st.top() == '[')
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
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        if (solve(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}