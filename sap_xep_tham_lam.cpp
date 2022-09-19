#include <bits/stdc++.h>
using namespace std;

// copy mảng a vào b, sort mảng b
// so sánh mỗi phần tử b[i] của mảng b với phần tử tương ứng a[i] của mảng a
// và ảnh của a[i] qua phần tử ở giữa của a là a[n - i - 1];
// vì khi reverse, phần tử a[i] chỉ có thể ở vị trí i hoặc n - i - 1
// nên nếu b[i] vừa khác a[i] và a[n - 1 - i] thì ko thể xảy ra
// tự lấy ví dụ để hiểu hơn
// 7    1 6 3 4 5 2 7
// Yes
int check(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] && a[n - i - 1] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        if (check(a, b, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}