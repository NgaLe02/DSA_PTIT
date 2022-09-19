#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long sum = 0;
        stack<long long> st;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                long long m1 = st.top();
                st.pop();
                long long m2 = st.top();
                st.pop();
                long long m;
                if (s[i] == '+')
                    m = m1 + m2;
                else if (s[i] == '-')
                    m = m2 - m1;
                else if (s[i] == '*')
                    m = m1 * m2;
                else if (s[i] == '/')
                    m = m2 / m1;
                else
                {
                    m = m2;
                    for (int i = 0; i <= m1 - 1; i++)
                    {
                        m *= m2;
                    }
                }
                st.push(m);
                //  cout << st.top() << endl;
            }
            else
            {
                st.push(s[i] - '0');
                //     cout << st.top() << endl;
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}