#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<pair<int, int>> edge;
bool used[1001];
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edge.push_back({x, y});
    }
}

void bfs(int u, int s, int t)
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
            if ((x == s && v == t) || (x == t && v == s))
            {
                continue;
            }
            else if (!used[x])
            {
                q.push(x);
                used[x] = true;
            }
        }
    }
}

// sap xep cac canh cau theo thu tu tu dien
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

void bridge()
{
    // dung de luu cac canh cau
    vector<pair<int, int>> res;
    // duyet lan luot cac canh cua do thi
    for (auto it : edge)
    {
        int s = it.first;
        int t = it.second;
        memset(used, false, sizeof(used));
        bfs(1, s, t);
        bool ok = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                ok = true;
                break;
            }
        }
        if (ok)
            res.push_back({min(s, t), max(s, t)});
    }
    sort(res.begin(), res.end(), cmp);
    for (auto it : res)
    {
        cout << it.first << " " << it.second << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        bridge();
        edge.clear();
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
}