#include <bits/stdc++.h>
using namespace std;

vector<int> lis[10001];
vector<int> pri;
int visit[10001];
int dis[10001];

int snt(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int check(int a, int b)
{
    int ans = 0;
    while (a > 0 && b > 0)
    {
        if (a % 10 != b % 10)
            ans++;
        a /= 10;
        b /= 10;
    }
    if (ans == 1)
        return 1;
    return 0;
}

void makePrime()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (snt(i))
        {
            pri.push_back(i);
        }
    }
    for (int i = 0; i < pri.size() - 1; i++)
    {
        for (int j = i + 1; j < pri.size(); j++)
        {
            if (check(pri[i], pri[j]))
            {
                lis[pri[i]].push_back(pri[j]);
                lis[pri[j]].push_back(pri[i]);
            }
        }
    }
}

int BFS(int s, int e)
{
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    dis[s] = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int x : lis[top])
        {
            if (visit[x] == 0)
            {
                visit[x] = 1;
                q.push(x);
                dis[x] = dis[top] + 1;
            }
        }
    }
    return dis[e];
}

int main()
{
    int t;
    cin >> t;
    makePrime();
    while (t--)
    {
        int s, e;
        cin >> s >> e;
        memset(visit, 0, sizeof(visit));
        cout << BFS(s, e) << endl;
    }
    return 0;
}