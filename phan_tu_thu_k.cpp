#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int b[], int n, int m, int k)
{
    int c[n + m];
    int i = 0, j = 0, l = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[l++] = a[i];
            i++;
        }
        else
        {
            c[l++] = b[j];
            j++;
        }
    }
    while (i < n)
    {
        c[l++] = a[i];
        i++;
    }
    while (j < m)
    {
        c[l++] = b[j];
        j++;
    }
    cout << c[k - 1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n];
        int b[m];
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        solve(a, b, n, m, k);
    }
    return 0;
}