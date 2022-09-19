#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int suml = 0, sumr = 0;
    suml = a[0];
    for (int i = 2; i < n; i++)
    {
        sumr += a[i];
    }
    if (suml == sumr)
        return 2;
    for (int i = 2; i < n - 1; i++)
    {
        suml += a[i - 1];
        sumr -= a[i];
        if (suml == sumr)
            return i + 1;
    }
    return -1;
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
        cout << solve(a, n) << endl;
    }
    return 0;
}