#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    for (int i = n - 1; i >= 2; i--)
    {
        int l = 0;
        int r = i - 1;
        while (l < r)
        {
            if (a[l] + a[r] == a[i])
            {
                return 1;
            }
            else if (a[l] + a[r] < a[i])
            {
                l++;
            }
            else
                r--;
        }
    }
    return 0;
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
        {
            cin >> x;
            x *= x;
        }
        if (solve(a, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}