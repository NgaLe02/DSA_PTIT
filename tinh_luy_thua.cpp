#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = power(a, b / 2);
    t = (t * t) % 1000000007;
    if (b % 2 == 1)
    {
        t = (t * a) % 1000000007;
    }
    return t;
}
int main()
{
    ll a;
    ll b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        cout << power(a, b) << endl;
    }
    return 0;
}