#include <bits/stdc++.h>
using namespace std;

long long power(long long n, long long k)
{
    if (k == 0)
        return 1;
    long long t = power(n, k / 2);
    t = (t * t) % 1000000007;
    if (k % 2 == 1)
    {
        t = (t * n) % 1000000007;
    }
    return t;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, k;
        cin >> n >> k;
        cout << power(n, k) << endl;
    }
    return 0;
}