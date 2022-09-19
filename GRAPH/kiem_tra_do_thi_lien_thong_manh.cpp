#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> adj[1001];
bool used[1001];

void dfs(int u)
{
    used[u] = true;
    for (int x : adj[u])
    {
        if (!used[x])
        {
            dfs(x);
        }
    }
}

void inp()
{
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof(used));
        dfs(i);
        for (int j = 1; j <= n; j++)
        {
            if (used[j] == false)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

// void bfs(int u)
// {
//     queue<int> q;
//     q.push(u);
//     used[u] = true;
//     while (!q.empty())
//     {
//         int top = q.front();
//         q.pop();
//         for (int x : adj[top])
//         {
//             q.push(x);
//             used[x] = true;
//         }
//     }
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        inp();
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}