#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt, best;
vector<int> adj[100001];
bool visited[100001];
void inp()
{
    cin >> n >> m;
     for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[n].begin(), adj[n].end());
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
            cnt++;
            dfs(v);
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
        best = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cnt = 1;
                dfs(i);
                best = max(cnt, best);
            }
        }
        cout << best << endl;
    }
    return 0;
}