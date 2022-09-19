#include <bits/stdc++.h>
using namespace std;

int check(int a[], int n, long long x)
{
    long long sum = a[0];
    int ind = 0; // chỉ sổ bắt đầu của cửa sổ
    for (int i = 1; i <= n; i++)
    {
        // nếu tổng lớn hơn x thì ta trừ đi các phần tử
        // từ chỉ số đầu của cửa sổ
        while (sum > x && ind < i - 1)
        {
            sum -= a[ind];
            ind++;
        }
        if (sum == x)
            return 1;
        if (i < n)
            sum += a[i];
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x;
        cin >> n >> x;
        int a[n];
        for (int &b : a)
            cin >> b;
        if (check(a, n, x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}