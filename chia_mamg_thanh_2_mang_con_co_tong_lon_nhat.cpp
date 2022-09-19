#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        long long sum1 = 0, sum2 = 0;
        for (int &x : a)
        {
            cin >> x;
            sum1 += x;
        }
        sort(a, a + n);
        int l = min(k, n - k);
        for (int i = 0; i < l; i++)
        {
            sum2 += a[i];
        }

        cout << sum1 - 2 * sum2 << endl;
    }
}