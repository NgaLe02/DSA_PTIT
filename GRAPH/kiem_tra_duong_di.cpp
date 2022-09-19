#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp()
{
    cin >> n >> m;
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
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        cin >> q;
        while (q--)
        {
            int s, e;
            cin >> s >> e;
            path(s, e);
        }
    }
    return 0;
}
/* Ý tưởng khác: Tính từng thành phần liên thông vào một biến nhớ
(vd: vector<int>adj[1001]) sau đó nếu cùng thành phần liên thông thì in YES ,
nguojc lại in NO */