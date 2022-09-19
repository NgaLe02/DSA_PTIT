#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int cnt = 0;

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

void bfs(int u)
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
            }
        }
    }
}

void connectedComponent(int e)
{
    memset(visited, false, sizeof(visited));
    bfs(1);
    if (!visited[e])
    {
        cnt = 1;
        cout << e << endl;
    }
}

int main()
{
    inp();
    for (int i = 2; i <= n; i++)
    {
        connectedComponent(i);
    }
    if (cnt == 0)
        cout << "0" << endl;
    return 0;
}