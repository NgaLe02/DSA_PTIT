#include <bits/stdc++.h>
using namespace std;
// ý tưởng y như bài xâu con chung dài nhất
int dp[1005][1005];
int LCS(string x, string y)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < x.size(); i++)
    {
        for (int j = 1; j < y.size(); j++)
        {
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x.size() - 1][y.size() - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        x = ' ' + x;
        y = ' ' + y;
        cout << LCS(x, y) << endl;
    }
    return 0;
}