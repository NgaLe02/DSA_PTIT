#include <bits/stdc++.h>
using namespace std;

// 3
// 4 3
// 1 3
// 3 4
// 1 4
// 4 4
// 3 1
// 2 3
// 3 4
// 1 2
// 10 4
// 4 3
// 5 10
// 8 9
// 1 2

int n, m;
vector<int> adj[1000001];
bool used[1000001];
int parent[1000001];
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (int x : adj[i])
    //     {
    //         cout << x << endl;
    //     }
    //     cout << endl;
    // }
}

int bfs(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int x : adj[v])
        {
            if (!used[x])
            {
                //    cout << x << endl;
                if (parent[x] != u)
                    return 0;
                q.push(x);
                used[x] = true;
            }
        }
    }
    return 1;
}

void solve()
{
    int ok = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof(used));
        for (int x : adj[i])
        {
            parent[x] = i;
        }
        if (!bfs(i))
        {
            ok = 1;
            cout << "NO" << endl;
            break;
        }
    }
    if (!ok)
        cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        solve();
    }
    return 0;
}