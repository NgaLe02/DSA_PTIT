#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    queue<string> q;
    q.push("1");
    while (1)
    {
        string tmp = q.front();
        q.pop();
        string t = tmp + "0";
        if (stoll(t) % n == 0)
        {
            cout << t << endl;
            return;
        }
        q.push(t);
        t = tmp + "1";
        if (stoll(t) % n == 0)
        {
            cout << t << endl;
            return;
        }
        q.push(t);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}