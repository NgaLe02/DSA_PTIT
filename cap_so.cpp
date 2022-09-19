#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v(105);
int dp[105];

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
int solve()
{
    sort(v.begin(), v.begin() + n, cmp);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].first > v[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    sort(dp, dp + n);
    return dp[n - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            cin >> v[i].second;
        }
        cout << solve() << endl;
        v.clear();
    }
    return 0;
}