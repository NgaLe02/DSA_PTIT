#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp()
{
    cin >> n >> m >> s >> e;
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            // ghi nhan cha cua v la u
            dfs(v);
        }
    }
}

void path(int s, int e)
{
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if (!visited[e])
    {
        cout << "-1" << endl;
    }
    else
    {
        vector<int> path;
        // tim duong di
        //  bat dau tu dinh t
        while (e != s)
        {
            path.push_back(e);
            // lat nguoc lai
            e = parent[e];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path)
        {
            cout << x << " ";
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
        path(s, e);
        cout << endl;
    }
    return 0;
}