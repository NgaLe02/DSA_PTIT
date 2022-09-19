#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[10000001];

int solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= x && a[i + 1] > x)
            return i + 1;
    }
    if (a[n - 1] <= x)
        return n;
    return -1;
}

int solve1()
{
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] <= x)
        {
            ans = m + 1;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve1() << endl;
    }
    return 0;
}