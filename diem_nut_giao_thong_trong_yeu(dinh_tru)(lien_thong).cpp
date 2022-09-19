#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<int> res;
bool used[1001];
int dem;

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
    used[u] = true;
    for (int v : adj[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
}

void dinhtru()
{
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof(used));
        //loai bo dinh i cung cac canh noi i
        used[i] = true;
        //khi tinh thanh phan lien thong, dfs(u), u != i
        if (i == 1)
            dfs(2);
        else
            dfs(1);
        bool ok = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                ok = 1;
                break;
            }
        }
        if (ok)
        {
            dem++;
            res.push_back(i);
        }
    }
    cout << dem << endl;
    for (int i = 0; i < dem; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        dem = 0;
        inp();
        dinhtru();
        res.clear();
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
}