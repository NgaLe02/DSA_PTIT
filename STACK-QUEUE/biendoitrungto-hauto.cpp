#include <bits/stdc++.h>
using namespace std;

int level(char c)
{
    // mức độ ưu tiên các dấu
    if (c == '^')
        return 4;
    else if (c == '/' || c == '*')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    return 1;
}

void solve()
{
    string s, a = "";
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] >= 'A' && s[i] <= 'Z')
            a += s[i];
        else if (s[i] >= 'a' && s[i] <= 'z')
            a += s[i];
        else if (s[i] == ')')
        {
            while (st.size() > 0 && st.top() != '(')
            {
                a += st.top();
                st.pop();
            }
            // loại bỏ dấu '(' vì vòng while dừng lại khi gặp '('
            st.pop();
        }
        else
        {
            while (st.size() > 0 && level(st.top()) >= level(s[i]))
            {
                a += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        if (st.top() != '(')
            a += st.top();
        st.pop();
    }
    cout << a << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}