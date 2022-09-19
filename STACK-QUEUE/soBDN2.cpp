#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(int n)
{
    queue<string> q;
    q.push("1");
    while (1)
    {
        string top = q.front();
        q.pop();
        if (stoll(top + "0") % n == 0)
        {
            cout << top + "0" << endl;
            break;
        }
        q.push(top + "0");
        if (stoll(top + "1") % n == 0)
        {
            cout << top + "1" << endl;
            break;
        }
        q.push(top + "1");
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