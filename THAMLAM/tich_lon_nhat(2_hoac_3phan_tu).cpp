#include <bits/stdc++.h>
using namespace std;

// tinhs tích của 2 số lớn nhất, 3 số lớn nhất, 2 số nhỏ nhất
// 2 số nhỏ nhất với số lớn nhất
// sau đó so sánh 4 tích
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
    {
        cin >> x;
    }
    sort(a, a + n);
    int max1 = a[0] * a[1];
    int max2 = a[n - 1] * a[n - 2];
    int max3 = max2 * a[n - 3];
    int max4 = max1 * a[n - 1];
    if (max2 > max1)
        max1 = max2;
    if (max3 > max1)
        max1 = max3;
    if (max4 > max1)
        max1 = max4;
    cout << max1;
    cout << endl;
    return 0;
}