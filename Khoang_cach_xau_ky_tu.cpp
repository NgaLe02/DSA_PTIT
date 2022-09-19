#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> inp;
vector<int> lis[10001];
int visited[10001];
int dis[10001];

int check(string a, string b)
{
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            ans++;
    }
    return 1;
    return 0;
}

void makeString()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (check(inp[i], inp[j]))
            {
                lis[i].push_back(j);
                lis[j].push_back(i);
            }
        }
    }
}

void BFS(int a, int b)
{
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    dis[a] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int x : lis[top])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
                dis[x] = dis[top] + 1;
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
        cin >> n;
        string s, t, x;
        cin >> s >> t;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x == s)
                a = i;
            if (x == t)
                b = i;
            inp.push_back(x);
        }
        makeString();
        memset(visited, 0, sizeof(visited));
        BFS(a, b);
        cout << dis[b] << endl;
    }
}