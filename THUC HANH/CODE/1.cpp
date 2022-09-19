#include <bits/stdc++.h>
using namespace std;

int s1, s2, f1, f2, n;
int a[11][11], d[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    d[x][y] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int u = top.first;
        int v = top.second;
        if (u == f1 && v == f2)
        {
            return true;
        }
        for (int k = 0; k < 8; k++)
        {
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && a[x1][y1] == 1)
            {
                a[x1][y1] = 0;
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
    cin >> s1 >> s2 >> f1 >> f2;
    n = 8;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 1;
        }
    }
    if (bfs(s1, s2) == true)
    {
        cout << d[f1][f2] << endl;
    }
    else
        cout << "-1\n"
             << endl;
    return 0;
}