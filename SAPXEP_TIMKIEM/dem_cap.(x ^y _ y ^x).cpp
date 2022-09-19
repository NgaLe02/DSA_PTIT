#include <bits/stdc++.h>
using namespace std;
// x < y thì x ^ y <  y ^ x;
// ngoại trừ:
// x == 2 : y = 3, y = 4 : ko thoả mãn
// x == 3 : y = 2 : thoả mãn
// x == 0 : ko thoả mãn với mọi y vì : (0 ^ y = 0 )< (y ^ 0 = 1)
// x == 1 : y = 0 : 1^0 = 1 > 0^1 = 0;
// O(nlogm + mlogn)
int find(int b[], int l, int r, int x)
{
    int pos = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (b[m] > x)
        {
            pos = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return pos;
}
int count(int x, int b[], int m, int cnt[])
{
    if (x == 0)
        return 0;
    if (x == 1)
        return cnt[0];

    // int *index = upper_bound(b, b + m, x);
    // int ans = (b + m) - index;
    int ans = 0;
    ans += (cnt[0] + cnt[1]);
    int index = find(b, 0, m - 1, x);
    if (index != -1)
    {
        ans += m - index;
    }
    if (x == 2)
    {
        ans = ans - (cnt[3] + cnt[4]);
    }
    if (x == 3)
    {
        ans += cnt[2];
    }
    return ans;
}

void count_pairs(int a[], int b[], int n, int m)
{
    int cnt[5] = {0};
    for (int i = 0; i < m; i++)
    {
        if (b[i] <= 4)
            cnt[b[i]]++;
    }
    sort(b, b + m);
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        dem += count(a[i], b, m, cnt);
    }
    cout << dem << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        count_pairs(a, b, n, m);
    }
    return 0;
}