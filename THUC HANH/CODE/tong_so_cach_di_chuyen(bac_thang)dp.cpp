#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// ý tưởng từ bài con ếch
long long count(int n, int k)
{
    long long cnt[n + 1];
    cnt[0] = 1;
    cnt[1] = 1;
    cnt[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        cnt[i] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                cnt[i] += (cnt[i - j] % mod);
            cnt[i] %= mod;
        }
    }
    return cnt[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << count(n, k) << endl;
    }
    return 0;
}
