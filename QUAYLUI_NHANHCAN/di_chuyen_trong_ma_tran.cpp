#include <bits/stdc++.h>
using namespace std;

int n, m, dem;
int a[101][101];

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    dem = 0;
}

void findThePath(int i, int j)
{
    if (i == n - 1 || j == m - 1)
    {
        dem++;
        return;
    }
    if (i + 1 < n)
    {
        findThePath(i + 1, j);
    }
    if (j + 1 < m)
    {
        findThePath(i, j + 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        findThePath(0, 0);
        cout << dem << endl;
    }
}