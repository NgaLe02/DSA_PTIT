#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool visited[1001];
int indegree[1001];
int cha[1001];
int mem;

void inp()
{
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= 1001; i++)
    {
        adj[i].clear();
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool dfs(int u, int parent)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            cha[v] = u;
            if (dfs(v, u))
                return true;
        }
        else if (v != parent)
        {
            mem = u;
            return true;
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        if (!dfs(1, 0))
        {
            cout << "NO\n";
        }
        else
        {
            vector<int> path;
            // tim duong di
            //  bat dau tu dinh t
            path.push_back(1);
            int e = mem;
            while (e != 1)
            {
                path.push_back(e);
                // lat nguoc lai
                e = cha[e];
            }
            path.push_back(1);
            reverse(path.begin(), path.end());
            for (int x : path)
            {
                cout << x << " ";
            }
        }
    }
}