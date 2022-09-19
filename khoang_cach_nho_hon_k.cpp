#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll find(ll a[], ll l, ll r, ll x)
{
    ll pos = -1;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (a[m] > x)
        {
            pos = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return pos;
}

void solve(ll a[], ll n, ll k)
{
    sort(a, a + n);
    ll ans = 0;
    ll r = n - 1;
    while (r >= 0)
    {
        ll s = a[r] - k;
        ll ind = find(a, 0, r - 1, s);
        if (ind >= 0)
            ans += (ll)(r - ind);
        r--;
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll &x : a)
            cin >> x;
        solve(a, n, k);
    }
    return 0;
}