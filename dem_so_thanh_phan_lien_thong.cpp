#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void inp()
{
    cin >> n >> m;
    memset(adj, 0, sizeof(adj));
    // danh sách cạnh sang danh sách kề
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void connectedComponent()
{
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        // Nếu đỉnh i chưa được thăm
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        connectedComponent();
    }
    return 0;
}