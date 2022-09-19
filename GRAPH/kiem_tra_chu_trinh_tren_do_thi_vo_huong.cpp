#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int parent[1001];
bool visited[1001];

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                parent[x] = v;
                // ghi nhan cha cua x la v
            }
            // tồn tại cạnh ngược (x, v)
            else if (x != parent[v])
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
        bool ok = false;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (bfs(i))
                {
                    ok = true;
                    break;
                }
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}