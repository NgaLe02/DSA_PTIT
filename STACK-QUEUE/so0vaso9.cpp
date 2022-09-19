#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> res;
ll ans[101];

void solve(int n)
{
    queue<string> q;
    q.push("9");
    res.push_back(9);
    while (1)
    {
        string top = q.front();
        q.pop();
        if (stoll(top) % n == 0)
        {
            cout << top << endl;
            break;
        }
        res.push_back(stoll(top + "0"));
        res.push_back(stoll(top + "9"));
        q.push(top + "0");
        q.push(top + "9");
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