#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[1005][1005];
// dp[n][k] là nCk
// sử dụng công thức: nCk = (n-1)C(k-1) + (n-1)Ck
void nCk()
{
    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    nCk();
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}