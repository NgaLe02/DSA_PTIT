#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    stack<int> st;
    while (t--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            int n;
            cin >> n;
            st.push(n);
        }
        else if (s == "POP")
        {
            if (!st.empty())
                st.pop();
        }
        else if (s == "PRINT")
        {
            if (st.empty())
            {
                cout << "NONE\n";
            }
            else
            {
                cout << st.top() << endl;
            }
        }
    }
}