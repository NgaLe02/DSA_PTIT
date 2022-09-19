#include <bits/stdc++.h>
using namespace std;
// Áp dụng đối với đồ thị có hướng, không có chu trinhg
// Nếu có chu trình sẽ ko có thứ tự topo
// Yêu cầu:Nếu có đường nối giữa đỉnh u và v thì u phải
// đứng trước v

int n, m;
vector<int> adj[1001];
bool visited[1001];
vector<int> topo; // lưu thứ tự topo

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
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
    // Khi này u đã được thăm xong
    // Đẩy u vào topo
    topo.push_back(u);
}

int main()
{
    inp();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int x : topo)
    {
        cout << x << " ";
    }
    cout << endl;
}
// Đỉnh nào được thăm xong sớm hơn sẽ được cho vào tôp sớm hơn
// tức là nó ko đi thăm được đỉnh nào khác cả