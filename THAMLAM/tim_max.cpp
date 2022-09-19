#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n)
{
    sort(a, a + n);
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (long)(sum % 1000000007 + (long)(a[i] * i) % 1000000007) % 1000000007;
    }
    cout << sum << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &x : a)
            cin >> x;
        solve(a, n);
    }
    return 0;
}