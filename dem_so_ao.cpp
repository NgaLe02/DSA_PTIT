#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, cnt;
char a[1001][1001];
void dfs(int x, int y)
{
    a[x][y] = '.';
    for (int k = 0; k < 8; k++)
    {
        int u = x + dx[k];
        int v = y + dy[k];
        if (u >= 0 && u < n && v >= 0 && v < m && a[u][v] == 'W')
        {
            dfs(u, v);
        }
    }
}
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
    cnt = 0;
}
int main()
{
    inp();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'W')
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}