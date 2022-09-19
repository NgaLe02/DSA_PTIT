#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    stack<char> st;
    char a[1000000];
    int cnt = 0;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            st.push(s[i]);
        if (s[i] >= 'a' && s[i] <= 'z')
            st.push(s[i]);
        if (!st.empty())
        {
            if (s[i] == '-')
                st.pop();
            else if (s[i] == '<')
            {
                a[cnt++] = st.top();
                st.pop();
            }
            else if (s[i] == '>')
            {
                for (int i = 0; i < cnt; i++)
                {
                    st.push(a[i]);
                }
                cnt = 0;
            }
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}

int main()
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}