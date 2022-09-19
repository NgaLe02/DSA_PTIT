#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void phanso(ll t, ll m)
{
    if (t == 0 && m == 0)
    {
        return;
    }
    if (m % t == 0)
    {
        cout << 1 << "/" << m / t;
        return;
    }
    if (t % m == 0)
    {
        cout << t / m;
        return;
    }
    if (t > m)
    {
        cout << t / m << " + ";
        phanso(t % m, m);
        return;
    }
    ll n = m / t + 1;
    cout << "1/" << n << " + ";
    phanso(t * n - m, m * n);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll t, m;
        cin >> t >> m;
        phanso(t, m);
        cout << endl;
    }
    return 0;
}