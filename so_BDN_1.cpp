#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve(ll n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    queue<string> q;
    q.push("1");
    ll ans = 1;
    while (1)
    {
        string tmp = q.front();
        q.pop();
        string t = tmp + "0";
        if (stoll(t) > n)
        {
            cout << ans << endl;
            return;
        }
        ans++;
        q.push(t);
        t = tmp + "1";
        if (stoll(t) > n)
        {
            cout << ans << endl;
            return;
        }
        ans++;
        q.push(t);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}