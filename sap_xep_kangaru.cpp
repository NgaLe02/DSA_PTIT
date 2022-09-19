#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int m = n / 2 + n % 2;
    int i = 0, j = m;
    int ans = 0;
    while (i < m && j < n)
    {
        if (a[i] * 2 <= a[j])
        {
            i++;
            j++;
            ans++;
        }
        else
        {
            j++;
        }
    }
    return n - ans;
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        cout << solve(a, n) << endl;
    }
    return 0;
}