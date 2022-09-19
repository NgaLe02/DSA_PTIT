#include <bits/stdc++.h>
using namespace std;

int knapStack(int a[], int c[], int n, int v)
{
    int dp[v + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = v; j >= 0; j--)
        {
            if (a[i - 1] <= j)
            {
                dp[j] = max(dp[j],
                            dp[j - a[i - 1]] + c[i - 1]);
            }
        }
    }
    return dp[v];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        cin >> n >> v;
        int a[n];
        int c[n];
        for (int &x : a)
            cin >> x;
        for (int &x : c)
            cin >> x;
        cout << knapStack(a, c, n, v) << endl;
    }
    return 0;
}