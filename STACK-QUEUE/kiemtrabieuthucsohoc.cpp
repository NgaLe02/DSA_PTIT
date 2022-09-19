/* Thừa khi giữa 2 dấu() có đúng 1 kí tự : VD:(a + (b)/c)
                         ko có phép tính :VD:((a+b))   */

#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    stack<char> st;
    int ok;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            ok = 1;
            char tmp = st.top();
            st.pop();
            while (tmp != '(')
            {
                if (tmp == '+' || tmp == '-' || tmp == '/' || tmp == '*')
                {
                    ok = 0;
                }
                tmp = st.top();
                st.pop();
            }
            if (ok == 1)
                break;
        }
        else
        {
            st.push(s[i]);
        }
    }
    return ok;
}

int main()
{
    int t;
    cin >> t;
    string s;
    cin.ignore();
    while (t--)
    {

        getline(cin, s);
        //   cout << solve(s) << endl;
        if (solve(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}