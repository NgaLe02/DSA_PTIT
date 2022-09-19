#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9 + 7;
const int max_index = INT_MIN;
const int min_index = INT_MAX;

const int maxn = 1001;
int a[maxn][maxn];
int n, s, t, u, v;
int d[maxn][maxn]; // luu so buoc di

void nhap()
{
    n = 8;
    cin >> s >> t >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 1;
        }
    }
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    d[i][j] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        if (x == u && y == v)
            return true;
        for (int k = 0; k < 8; k++)
        {
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && a[x1][y1] == 1)
            {
                a[x1][y1] = 0; // da tham
                d[x1][y1] = d[x][y] + 1;
                q.push({x1, y1});
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    nhap();
    if (bfs(s, t))
    {
        cout << d[u][v] << endl;
    }
    else
        cout << -1 << endl;
}