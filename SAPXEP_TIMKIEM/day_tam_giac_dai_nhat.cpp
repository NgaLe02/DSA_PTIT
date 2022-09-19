#include <bits/stdc++.h>
using namespace std;

void DP(int a[], int n)
{
    int L1[n];
    int L2[n];
    for (int i = 0; i < n; i++)
    {
        L1[i] = 1;
        L2[i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] > a[i])
        {
            L1[i + 1] += L1[i];
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i - 1] > a[i])
        {
            L2[i - 1] += L2[i];
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (L1[i] + L2[i] - 1 > max)
        {
            max = L1[i] + L2[i] - 1;
        }
    }
    cout << max << endl;
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
        DP(a, n);
    }
    return 0;
}