#include <bits/stdc++.h>
using namespace std;

// sort mảng a theo thứ tự tăng dần
// sort mảng b theo thứ tự giảm dần
typedef long long ll;

int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n], b[n];
        for (ll &x : a)
            cin >> x;
        for (ll &x : b)
            cin >> x;
        sort(a, a + n);
        sort(b, b + n, cmp);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i] * b[i];
        }
        cout << sum << endl;
    }
}