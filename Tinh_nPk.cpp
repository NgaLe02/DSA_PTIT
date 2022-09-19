#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[1001][1001];
// dp[n][k] là nPk
// sử dụng công thức: nPk = (n-1)Pk + k * (n-1)C(k-1)
void nCk()
{
    for (int i = 0; i < 1001; i++)
        dp[i][0] = 1;
    for (int i = 1; i < 1001; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j] + j * dp[i - 1][j - 1]) % mod;
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