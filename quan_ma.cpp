#include <bits/stdc++.h>
using namespace std;

int visited[10][10];
int dis[10][10];

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int si, sj, ei, ej;

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    dis[i][j] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == ei && top.second == ej)
        {
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int i1 = top.first + dx[i];
            int j1 = top.second + dy[i];
            if (i1 >= 1 && j1 >= 1 && i1 <= 8 && j1 <= 8 && !visited[i1][j1])
            {
                q.push({i1, j1});
                visited[i1][j1] = 1;
                dis[i1][j1] = dis[top.first][top.second] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        si = s[1] - '0';
        sj = s[0] - 'a' + 1;
        ei = t[1] - '0';
        ej = t[0] - 'a' + 1;
        memset(visited, 0, sizeof(visited));
        BFS(si, sj);
        cout << dis[ei][ej] << endl;
    }
    return 0;
}