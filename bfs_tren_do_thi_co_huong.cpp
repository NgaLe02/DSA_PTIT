#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> adj[1001];
bool visited[1001];

void inp()
{
    cin >> n >> m >> s;
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
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
        bfs(s);
        cout << endl;
    }
    return 0;
}