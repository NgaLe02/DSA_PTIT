#include <bits/stdc++.h>
using namespace std;

int b[1000000] = {0};
int a[1000000] = {0}; // lưu chỉ số bắt đầu của ngoăc đúng

int solve(string s)
{
    stack<int> st;
    // lưu chỉ số của dấu
    int cnt = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
                return -1;
            else
            {
                int m = -1;
                for (int i = 0; i < cnt; i++)
                {
                    if (st.top() > a[i])
                    {
                        m = i;
                        cout << "m=" << m << endl;
                        break;
                    }
                }

                if (m > -1)
                {
                    for (int i = m; i < cnt; i++)
                        b[i]++;
                    st.pop();
                }
                else
                {
                    a[cnt++] = st.top();
                    b[cnt]++;
                    st.pop();
                }
            }
        }
    }
    if (!st.empty())
        return -1;
    //  cout << "cnt=" << cnt << endl;
    //  for (int i = 1; i < cnt; i++)
    //     cout << b[i] << " ";
    //  cout << endl;
    int m = *max_element(b + 1, b + cnt);
    return m;
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
        cout << solve(s) << endl;
    }
    return 0;
}