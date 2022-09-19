#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[200001];
bool visited[200001];

void inp()
{
    cin >> n >> m;
    //danh sách cạnh sang danh sách kề
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u, int k)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v] && v != k)
        {
            dfs(v, k);
        }
    }
}

void connectedComponent(int k)
{
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        // Nếu đỉnh i chưa được thăm
        if (!visited[i] && i != k)
        {
            cnt++;
            dfs(i, k);
        }
    }
    cout << cnt << endl;
}

int main()
{
    inp();
    for (int i = 1; i <= n; i++)
    {
        connectedComponent(i);
    }
    return 0;
}