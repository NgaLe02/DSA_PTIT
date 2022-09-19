#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int b[], int n, int m)
{
    int c[n + m - 1];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < n + m - 1; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        solve(a, b, n, m);
    }
    return 0;
}