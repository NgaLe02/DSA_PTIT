#include <bits/stdc++.h>
using namespace std;

int dp[101][25001];
// dp[i][j]: khối lượng lớn nhất khi chọn tới con bò thứ i
// với trọng lượng tối đa là j
int solve(int a[], int n, int c)
{
    memset(dp, 0, sizeof(dp));
    // khối lượng lớn nhất khi chưa có con bò nào
    // với trọng lượng lớn nhất là i( từ 0 tới c)
    for (int i = 0; i <= c; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        // khối lượng lớn nhất khi chọn tới con bò thứ i
        // với trọng lượng lớn nhất từ 1-> c
        for (int j = 1; j <= c; j++)
        {
            // nếu khối lượng của con bò thứ i
            // nhỏ hơn trọng lượng lớn nhất c
            // sẽ có 2 th xảy ra :
            // không thêm con bò vào xe tải hoặc thêm vào xe tải
            if (a[i] <= j)
                // ko thêm: dp[i-1][j]
                //-> khối lượng lớn nhất chọn tới con bò thứ i-1 với trọng lượng lớn nhất là j
                // thêm: dp[i-1[j-a[i]]] + a[i]
                //->khối lượng lớn nhất chọn tới con bò thứ i-1
                // với trọng lượng lớn nhất là j-a[i], sau đó cộng với a[i]
                // ta phải lấy j-a[i] thì lúc sau khi thêm a[i] ta mới
                // được trọng lượng lớn nhất là j, nếu ko trừ
                // ta sẽ có trọng lượng lớn nhất là j+ a[i]
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - a[i]] + a[i]);
            else
                // nếu a[i]>j
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][c];
}
int main()
{
    int c, n;
    cin >> c >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << solve(a, n, c) << endl;
    return 0;
}