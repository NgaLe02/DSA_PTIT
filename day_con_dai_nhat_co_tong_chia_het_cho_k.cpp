#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
// dp[i][j] độ dài dãy con lớn nhất xét từ a1 tới ai
// có tổng và j chia hết cho k
// ở đây, t chỉ cần chứa tổng % k hay là j thay vì chứa tổng
// bởi vì thông tin là đủ để ta giải quyết bài toán
int solve(int a[], int n, int k)
{
    // chia dư cho k
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % k;
    // độ dài dãy con lớn nhất khi chưa có phần tử trong a[i]
    // với i là số dư của 1 số khi chia cho k
    for (int i = 1; i < k; i++)
        dp[0][i] = -1e9;
    // độ dài lớn nhất của dãy con chưa có phần tử trong mảng a
    // chia hết cho k
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            // nếu không thêm phần tử a[i]
            //-> dp[i][j] = dp[i-1][j]
            //-> độ dài lớn nhất từ ptu a1 tới a(i-1) có tổng chia dư cho k là j
            // nếu thêm phần tử a[i]
            //-> độ dài lớn nhất từ ptu a1 tới a(i-1) có tổng chia dư là j-a[i]+k
            //->(j-a[i]) để khi thêm ptu a[i] thì số chia dư vẫn là j
            // -> cần cộng thêm k để phòng th j-a[i]<0
            dp[i][j] = max(dp[i - 1][j],
                           dp[i - 1][(j - a[i] + k) % k] + 1);
        }
    }
    return dp[n][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << solve(a, n, k) << endl;
    }
    return 0;
}