#include <bits/stdc++.h>
using namespace std;
void solve()
{
    queue<int> q;
    int n, mem = 0;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a == 1)
            cout << q.size() << endl;
        else if (a == 2)
        {
            if (!q.empty())
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else if (a == 3)
        {
            int b;
            cin >> b;
            q.push(b);
        }
        else if (a == 4)
        {
            if (!q.empty())
                q.pop();
        }
        else if (a == 5)
        {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << "-1" << endl;
        }
        else
        {
            if (!q.empty())
                cout << q.back() << endl;
            else
                cout << "-1" << endl;
        }
        mem = a;
    }
    if (mem == 3 || mem == 4)
        cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}