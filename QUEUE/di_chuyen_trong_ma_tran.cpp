#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001];
int visited[1001][1001];
int dis[1001][1001];

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    memset(dis, 0, sizeof(dis));
}

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    dis[i][j] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int u = top.first;
        int v = top.second;
        if (u == n && v == m)
        {
            return;
        }
        if (a[u][v] + v >= 1 && a[u][v] + v <= m && !visited[u][a[u][v] + v])
        {
            q.push({u, a[u][v] + v});
            visited[u][a[u][v] + v] = 1;
            dis[u][a[u][v] + v] = dis[u][v] + 1;
        }
        if (a[u][v] + u >= 1 && a[u][v] + u <= n && !visited[a[u][v] + u][v])
        {
            q.push({a[u][v] + u, v});
            visited[a[u][v] + u][v] = 1;
            dis[a[u][v] + u][v] = dis[u][v] + 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        BFS(1, 1);
        if (dis[n][m] == 0)
            cout << "-1\n";
        else
            cout << dis[n][m] << endl;
    }
    return 0;
}