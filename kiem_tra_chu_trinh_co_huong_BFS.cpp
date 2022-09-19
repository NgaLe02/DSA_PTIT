#include <bits/stdc++.h>
using namespace std;

// Thuật toán xoá dần đỉnh
// Áp dụng: Nếu đồ thị có hướng có chu trình thì
// thứ tự topo sẽ không thể có đầy đủ tất cả các đỉnh

int n, m;
vector<int> adj[1001];
int indegree[1001]; // lưu bán bậc vào của các đỉnh

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
}

int Kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
        cnt++;
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            indegree[v]--;
            if (!indegree[v])
                q.push(v);
        }
    }
    return cnt == n;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        if (!Kahn())
            cout << "YES\n";
        else
            cout << "NO\n";
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            indegree[i] = 0;
        }
    }
    return 0;
}
