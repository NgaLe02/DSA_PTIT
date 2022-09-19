#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
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
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void dinhTru()
{
    for (int i = 1; i <= n; i++)
    {
        // loại bỏ đỉnh i cùng các cạnh nối với i
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        // Khi tính thành phần liên thông, dfs(u), u khác i
        if (i == 1)
            dfs(2);
        else
            dfs(1);
        bool ok = true;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            cout << i << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        dinhTru();
        cout << endl;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}