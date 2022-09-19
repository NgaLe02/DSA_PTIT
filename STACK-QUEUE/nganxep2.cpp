#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    stack<int> st;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        if (s == "POP")
        {
            if (st.size() > 0)
            {
                st.pop();
            }
        }
        else if (s == "PRINT")
        {
            if (st.size() > 0)
            {
                cout << st.top() << endl;
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
        else
        {
            stringstream ss(s);
            string t;
            while (ss >> t)
            {
            }
            int m = (int)stoll(t);
            st.push(m);
        }
    }
    return 0;
}