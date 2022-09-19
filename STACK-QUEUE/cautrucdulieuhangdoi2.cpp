#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void solve()
{
    string s;

    cin >> s;
    if (s == "POP")
    {
        if (!q.empty())
            q.pop();
    }
    else if (s == "PRINTFRONT")
    {
        //  cout << q.size() << endl;
        if (!q.empty())
            cout << q.front() << endl;
        else
            cout << "NONE" << endl;
    }
    else if (s == "PUSH")
    {
        int t;
        cin >> t;
        q.push(t);
        // cout << q.front() << endl;
    }
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