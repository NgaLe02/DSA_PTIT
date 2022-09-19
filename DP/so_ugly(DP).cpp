#include <bits/stdc++.h>
using namespace std;
// xem so_ugly.cpp

// số xấu là các số như 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15
// Số xấu chỉ có thừa số nguyên tố là 2, 3, 5 nên
// các số xấu được phân chia thành 3 dãy con
// 1*2, 2*2, 3*2, 4*2, 5*2, 6*2, 7*2,... a
// 1*3, 2*3, 3*3, 4*3, 5*3, 6*3, 7*3,... b
// 1*5, 2*5, 3*5, 4*5, 5*5, 6*5, 7*5,... c
// vì vậy, ta sẽ tìm các số xấu từ 3 dãy con trên,
// mỗi bước ta chọn số nhỏ nhất và tiếp tục làm như vậy
int Ugly(int n)
{
    int ugly[n]; // mảng chứa số xấu
    // ba biến trỏ tới phần tử thứ nhất của mảng ugly
    int i2 = 0, i3 = 0, i5 = 0;
    // ba lựa chọn cho số xấu tiếp theo
    int mul2 = 2, mul3 = 3, mul5 = 5;
    // số xấu tiếp theo
    int nextUgly = 1;
    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        nextUgly = min(mul2, min(mul3, mul5));
        ugly[i] = nextUgly;
        if (nextUgly == mul2)
        {
            i2++;
            mul2 = ugly[i2] * 2;
        }
        if (nextUgly == mul3)
        {
            i3++;
            mul3 = ugly[i3] * 3;
        }
        if (nextUgly == mul5)
        {
            i5++;
            mul5 = ugly[i5] * 5;
        }
    }
    return nextUgly;
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
    return 0;
}