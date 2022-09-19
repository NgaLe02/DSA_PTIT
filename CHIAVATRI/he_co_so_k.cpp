#include <bits/stdc++.h>
using namespace std;

// Bước 1: tạo a, b có độ dài bằng nhau , bằng cách
// thêm '0' vào string có độ dài ngắn hơn
// Bước 2: Cộng từ dưới lên
// (xem code để hiểu hơn)
string solve(int k, string a, string b)
{
    while (a.length() < b.length())
        a = '0' + a;
    while (b.length() < a.length())
        b = '0' + b;
    int carry = 0, ans = 0;
    string sum = "";
    for (int i = a.length() - 1; i >= 0; i--)
    {
        ans = carry + (a[i] - '0') + (b[i] - '0');
        carry = ans / k;
        ans = ans % k;
        sum = (char)(ans + '0') + sum;
    }
    if (carry > 0)
        sum = (char)(carry + '0') + sum;
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string a, b;
        cin >> k >> a >> b;
        cout << solve(k, a, b) << endl;
    }
    return 0;
}