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
        long long n, k, m;
        cin >> n;
        m = n;
        k = 0;
        while (m > 0)
        {
            k = k * 10 + m % 10;
            m /= 10;
        }
        cout << power(n, k) << endl;
    }
    return 0;
}