#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    set<int> se;
    se.insert(n);
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == 1)
            return top.second;
        if (top.first - 1 == 1)
            return top.second + 1;
        if (se.find(top.first - 1) == se.end() && top.first > 1)
        {
            q.push({top.first - 1, top.second + 1});
            se.insert(top.first - 1);
        }
        for (int i = 2; i * i <= top.first; i++)
        {
            if (top.first % i == 0)
            {
                if (se.find(top.first / i) == se.end())
                {
                    q.push({top.first / i, top.second + 1});
                    se.insert(top.second / i);
                }
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
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}