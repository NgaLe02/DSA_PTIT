#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{

    stack<int> st;
    string s;
    int n;

    while (cin >> s)
    {
        if (s == "pop")
        {
            st.pop();
        }
        else if (s == "show")
        {
            if (st.size() > 0)
            {
                vector<int> v;
                while (!st.empty())
                {
                    v.push_back(st.top());
                    st.pop();
                }
                reverse(v.begin(), v.end());
                for (int x : v)
                {
                    cout << x << " ";
                    st.push(x);
                }
                cout << endl;
            }
            else
            {
                cout << "empty" << endl;
            }
        }
        else if (s == "push")
        {
            cin >> n;
            st.push(n);
        }
    }
    return 0;
}