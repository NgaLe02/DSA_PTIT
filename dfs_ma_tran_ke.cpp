#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int n;
void dfs(int u)
{
    cout << u << " ";
    for (int i = 1; i <= n; i++)
    {
        if (a[u][i] == 1)
        {
            a[u][i] = a[i][u] = 0;
            dfs(i);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(1);
}