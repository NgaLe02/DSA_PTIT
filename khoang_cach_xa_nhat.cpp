#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n)
{
    // tạo mảng b
    // phần tử b[i] là phần tử lớn nhất kể từ phần tử
    // thứ i tới n - 1 của mảng a
    int b[n];
    memset(b, INT_MIN, sizeof(b));
    for (int i = n - 1; i >= 0; i--)
    {
        b[i] = max(b[i + 1], a[i]);
        // gtri lớn nhất của mảng a từ (i + 1 -> n - 1) là b[i + 1]
        //=> gtri lớn nhất của mảng a từ (i -> n - 1) là
        // max(b[i + 1], a[i])
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // binary search
        // tìm phần tử lớn hơn a[i] nằm ngoài cùng bên phải của a[i]
        int l = i + 1, r = n - 1, res = i;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[i] < b[m])
            {
                res = max(res, m);
                l = m + 1;
            }
            else
                r = m - 1;
        }
        ans = max(ans, res - i);
    }
    if (ans == 0)
        cout << "-1\n";
    else
        cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &x : a)
            cin >> x;
        solve(a, n);
    }
    return 0;
}