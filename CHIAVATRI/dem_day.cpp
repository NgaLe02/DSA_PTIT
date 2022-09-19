#include <bits/stdc++.h>
using namespace std;
// số cách chính là 2^(n-1)

long long power(long long n, long long k)
{
    if (k == 0)
        return 1;
    long long t = power(n, k / 2);
    t = (t * t) % 123456789;
    if (k % 2 == 1)
    {
        t = (t * n) % 123456789;
    }
    return t;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << power(2, n - 1) << endl;
    }
}