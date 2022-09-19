#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == k)
        {
            cout << m + 1 << endl;
            return;
        }
        else if (a[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int &x : a)
            cin >> x;
        solve(a, n, k);
    }
    return 0;
}