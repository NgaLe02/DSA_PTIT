#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int color[1001];
// color[i] = 1; màu xám, đang thăm
//          = 2; màu đen, đã thăm xong
//          = 0; màu trắng, chưa được thăm

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
}

bool DFS(int u)
{
    color[u] = 1; // đăng thăm
    for (int v : adj[u])
    {
        if (!color[v]) // nếu v chưa được thăm
        {
            if (DFS(v))
                return true;
        }
        else if (color[v] == 1) // nếu đang thăm
        {
            // tồn tại cạnh ngược
            return true;
        }
    }
    color[u] = 2; // đã thăm xong
    return false;
}

void detectCycle()
{
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if (DFS(i))
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
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        detectCycle();
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
}