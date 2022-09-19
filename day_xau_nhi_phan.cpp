#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, fb[93];
// như bài dãy xâu fibonaci
char find(ll n, ll k)
{
    if (n == 1)
        return '0';
    if (n == 2)
        return '1';
    if (k <= fb[n - 2])
        return find(n - 2, k);
    return find(n - 1, k - fb[n - 2]);
}
int main()
{
    int t;
    cin >> t;
    fb[1] = 1;
    fb[2] = 1;
    for (int i = 3; i <= 92; i++)
    {
        fb[i] = fb[i - 1] + fb[i - 2];
    }
    while (t--)
    {
        cin >> n >> k;
        cout << find(n, k) << endl;
    }
    return 0;
}