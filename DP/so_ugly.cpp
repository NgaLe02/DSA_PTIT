#include <bits/stdc++.h>
using namespace std;

// chia a cho luỹ thừa lớn nhất của b
int maxDivide(int a, int b)
{
    while (a % b == 0)
    {
        a /= b;
    }
    return a;
}

// kiểm tra xem n có phải số xấu hay không
// số xấu là số chỉ số thừa số nguyên tố là 2, 3, 5
// để kiểm tra, ta chia số đó cho luỹ thừa chia hết lớn nhất
// của 2, 3, 5.
// sau khi chia ta nhận được thì số đó là số xấu, ngược lại
// đó không phải số xấu
int isUgly(int n)
{
    int tmp = maxDivide(n, 2);
    tmp = maxDivide(tmp, 3);
    tmp = maxDivide(tmp, 5);
    if (tmp == 1)
        return 1;
    return 0;
}

int Ugly(int n)
{
    int cnt = 1; // đếm số Ugly thứ cnt
    int i = 1;   // số tự nhiên i
    while (cnt < n)
    {
        i++;
        if (isUgly(i))
            cnt++;
    }
    return i;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << Ugly(n) << endl;
    }
}