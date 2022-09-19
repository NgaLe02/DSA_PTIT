#include <bits/stdc++.h>
using namespace std;

//Đặt L[i, t] = 1 nếu có thể tạo ra tổng bằng t
// từ dãy con gồm các phần tử nằm trong dãy từ A1 -> Ai
// và ngược lại L[i, t] = 0.
// Nếu L[n, S] = 1 thì ta có thể tạo ra dãy con
// có tổng bằng S từ A1 -> AN.
// Cài đặt:
// Nếu áp dụng luôn công thức
// trên ta cần dùng mảng 2 chiều.
// Ta có thể nhận xét rằng để có thể tính dòng thứ i,
// ta chỉ cần dòng i-1.
// Bảng phương án khi đó chỉ cần mảng 1 chiều L[0…S]
// và được tính như sau:
int check(int a[], int n, int s)
{
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    // chưa thể tạo dãy con có tổng bằng s
    dp[s] = 0;
    // dãy con ko có phần tử nào của mảng có tổng bằng 0
    dp[0] = 1;
    // duyệt từ đầu mảng với cuối mảng
    for (int i = 0; i < n; i++)
    {
        // duyệt từ s trở về giá trị a[i]
        // bởi nếu j < a[i] ta sẽ bị tràn mảng
        // ở lệnh dòng 30
        for (int j = s; j >= a[i]; j--)
        {
            // nếu tổng j - a[i] đã có
            // thì khi ta cộng thêm a[j]
            // ta sẽ có tổng j
            if (dp[j - a[i]] == 1)
                dp[j] = 1;
        }
    }
    // nếu dp[s] = 1 tức có thể có dãy con có tổng bằng s
    return dp[s];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int a[n];
        for (int &x : a)
            cin >> x;
        if (check(a, n, s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}