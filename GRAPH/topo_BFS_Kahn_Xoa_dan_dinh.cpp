#include <bits/stdc++.h>
using namespace std;
// Áp dụng đối với đồ thị có hướng, không có chu trinhg
// Nếu có chu trình sẽ ko có thứ tự topo
// Yêu cầu:Nếu có đường nối giữa đỉnh u và v thì u phải
// đứng trước v
// Thuật toán xoá dần đỉnh
// Áp dụng: Nếu đồ thị có hướng có chu trình thì thứ tự topo
// sẽ không thể có đầy đủ tất cả các đỉnh

int n, m;
vector<int> adj[1001];
bool visited[1001];
int indegree[1001]; // lưu bán bậc vào của các đỉnh
vector<int> topo;   // lưu thứ tự topo

void inp()
{
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    memset(visited, false, sizeof(visited));
}

//
void Kahn()
{
    queue<int> q;
    // ta sẽ đẩy các đỉnh có bán bậc vào = 0 vào queue
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            // khi xoá đỉnh u khỏi đồ thị
            //  bán bậc vào của các đỉnh v nối với u
            //  sẽ bị giảm đi 1
            indegree[v]--;
            // nếu bán bậc vào = 0 thì ta cho vào quêu để tiếp
            // tục duyệt
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    for (int x : topo)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    inp();
    Kahn();
    return 0;
}
