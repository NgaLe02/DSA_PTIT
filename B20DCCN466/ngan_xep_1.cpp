#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s == "pop")
        {
            st.pop();
        }
        else if (s == "show")
        {
            if (st.empty())
            {
                cout << "empty\n";
            }
            else
            {
                vector<int> tmp;
                while (!st.empty())
                {
                    tmp.push_back(st.top());
                    st.pop();
                }
                for (int i = tmp.size() - 1; i >= 0; i--)
                {
                    st.push(tmp[i]);
                }
                for (int i = tmp.size() - 1; i >= 0; i--)
                    cout << tmp[i] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}