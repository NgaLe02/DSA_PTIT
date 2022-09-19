#include <bits/stdc++.h>
using namespace std;

int check(int n)
{
    set<int> s;
    while (n > 0)
    {
        if (n % 10 > 5)
            return 0;
        if (s.find(n % 10) != s.end())
            return 0;
        s.insert(n % 10);
        n /= 10;
    }
    return 1;
}
void solve(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (check(i))
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}