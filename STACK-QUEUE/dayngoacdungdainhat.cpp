#include <bits/stdc++.h>

using namespace std;

int longest(string s)
{
    stack<int> st;
    int ans = 0;
    st.push(-1); // ap dung cho ngoac dau tien
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (!st.empty())
            {
                ans = max(ans, i - st.top());
            }
            else
                st.push(i);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << longest(s) << endl;
    }
}