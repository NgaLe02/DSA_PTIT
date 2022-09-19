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
                parent[x] = v;
                //ghi nhan cha cua x la v
            }
        }
    }
}

void path(int s, int e)
{
    int mem = e;
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(s);
    if (!visited[e])
    {
        cout << "-1" << endl;
    }
    else
    {
        vector<int> path;
        // truy vet duong di
        // bat dau tu dinh e
        while (e != s)
        {
            path.push_back(e);
            //lat nguoc lai
            e = parent[e];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path)
        {
            cout << x << " ";
            // if (x != mem)
            //   cout << " -> ";
        }
        cout << endl;
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
    }
    return 0;
}