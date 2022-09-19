#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int a[1001][1001];
bool visited[1001][1001];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void in()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    cnt = 0;
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u >= 0 && v >= 0 && u < n && v < m && a[u][v] == 'W' && !visited[u][v])
        {
            dfs(u, v);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    t = 1;
    while (t--)
    {
        in();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'W' && !visited[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}