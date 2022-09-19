#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int d[1001][1001];
//d[i][j]: lưu số bước đi tối thiểu từ ô start đến ô hiejn taị
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(d, 0, sizeof(d));
}

int solve()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    d[1][1] = 0;
    // số bước dịch chuyển là 0
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        //duyệt 4 ô xung quanh
        int i = top.first;
        int j = top.second;
        for (int k = 0; k < 4; k++)
        {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (a[i1][j1] && i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m)
            {
                if (i1 == n && j1 == m)
                    return d[i][j] + 1;
                q.push({i1, j1});
                d[i1][j1] = d[i][j] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    inp();
    if (a[1][1] && a[n][m])
    {
        cout << solve() << endl;
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
