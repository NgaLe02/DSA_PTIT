#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
// dp[i][j] = 1 nếu xâu con từ i tới j đối xứng,
// và ngược lại
// nếu xâu con từ (i+1, j-1) đối xứng và s[i]=s[j]
// thì xâu con từ (i,j) đỗi xứng
// ta phải kiểm tra xâu con đối xứng có độ dài là 1, 2 trước bởi vì
// trong khi kiểm tra dp[i+1][j-1] trong TH
// length = 1, vd i=2;j=2 thì(3,1) ko nằm trong (2,2)
// length = 2, vd i=2,j=3 thì(3,2) ko nằm trong(2,3)
int solve(string s)
{
    memset(dp, 0, sizeof(dp));
    // độ dài xâu con đối xứng dài nhất
    int res = 1;
    int n = s.size();
    // tất cả các xâu con có độ dài = 1 đều đối xứng
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    // kiểm tra xâu con có độ dài bằng 2
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            res = 2;
        }
    }
    // kiểm tra xâu con có độ dài lớn hơn 2
    // k là độ dài xâu con
    for (int k = 3; k <= n; k++)
    {
        // i là chỉ số bắt đầu
        for (int i = 0; i < n - k + 1; i++)
        {
            // xâu con có chỉ số bắt đầu là i, độ dài là k
            // nên chỉ số kết thúc xâu con là j=i+k-1
            int j = i + k - 1;
            // nếu xâu con từ (i+1, j-1) đối xứng và s[i]=s[j]
            // thì xâu con từ (i,j) đỗi xứng
            if (dp[i + 1][j - 1] && s[i] == s[j])
            {
                dp[i][j] = 1;
                // cập nhật lại độ dài lớn nhất
                if (k > res)
                    res = k;
            }
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}