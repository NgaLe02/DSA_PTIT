#include <bits/stdc++.h>
using namespace std;

int k, n, m;
vector<int> adj[1001];
bool visited[1001];
int init[1001];
map<int, int> ma;

void inp()
{
    cin >> k >> n >> m;
    init[k];
    for (int i = 0; i < k; i++)
    {
        cin >> init[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u)
{
    visited[u] = true;
    ma[u]++;
    for (int x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}

void solve()
{
    for (int x : init)
    {
        memset(visited, false, sizeof(visited));
        dfs(x);
    }
    int ans = 0;
    for (auto it : ma)
    {
        if (it.second == k)
            ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}
int main()
{
    inp();
    solve();
    return 0;
}