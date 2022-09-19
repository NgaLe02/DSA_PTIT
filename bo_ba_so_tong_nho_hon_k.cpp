#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll a[], int n, ll s)
{
    ll ans = 0;
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (a[i] + a[j] + a[k] >= s)
            {
                k--;
            }
            else
            {
                ans += k - j;
                j++;
            }
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
        int n;
        ll s;
        cin >> n >> s;
        ll a[n];
        for (ll &x : a)
            cin >> x;
        solve(a, n, s);
    }
    return 0;
}