#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
// xâu con chung dài nhất đến phần tử thứ i của xâu x,
// và phần tử thứ j của xâu i
int LCS(string x, string y)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < x.size(); i++)
    {
        for (int j = 1; j < y.size(); j++)
        {
            // nếu x[i] = y[j]
            // thì xâu con chung dài nhất tới phần tử thứ i của xâu x,
            // phần từ thứ j của xâu y là:
            // xâu con chung dài nhất tới phần tử thứ i-1 của xâu x,
            // phần từ thứ j-1 của xâu y + 1
            // tứ dp[i-1][j-1] + 1
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                // ngược lại, kết quả sẽ là xâu con chung dài nhất tới
                // phần tứ thứ i-1 xâu x, phần tử thứ j của xâu y
                // hoặc
                // xâu con chung dài nhất tới
                // phần tứ thứ i xâu x, phần tử thứ j-1 của xâu y
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