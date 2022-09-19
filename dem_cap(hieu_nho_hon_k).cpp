#include <bits/stdc++.h>
using namespace std;

// O(n^2)
void solve(int a[], int n, int k)
{
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = a[i] + k;
        int c;
        int ind = lower_bound(a, a + n, tmp) - a;
        c = (ind - i - 1);
        if (c >= 1)
            ans += c;
    }
    cout << ans << endl;
}

int first_pos(int a[], int l, int r, int x)
{
    int pos = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] > x)
        {
            pos = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return pos;
}

// a[r] - a[l] < k
//=> a[l] > a[r] - k
//  Đếm phần tử đầu tiên trong đoạn [0, r - 1] mà lớn hơn a[r] - k;
void solve1(int a[], int n, int k)
{
    sort(a, a + n);
    long long ans = 0;
    int r = n - 1;
    while (r >= 0)
    {
        int s = a[r] - k;
        int ind = first_pos(a, 0, r - 1, s);
        if (ind >= 0)
            ans += (long long)(r - ind);
        r--;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int &x : a)
            cin >> x;
        solve(a, n, k);
    }
    return 0;
}