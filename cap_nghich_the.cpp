#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<ll> a;

ll merge(int l, int m, int r)
{
    ll tmp[r + 1];
    ll ans = 0;
    int i = l, j = m, k = l;
    while (i < m && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = a[j];
            ans += m - i;
            j++;
            k++;
        }
    }
    while (i < m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l; i <= r; i++)
    {
        a[i] = tmp[i];
    }
    return ans;
}

ll mergeSort(int l, int r)
{
    ll ans = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        ans += mergeSort(l, m);
        ans += mergeSort(m + 1, r);
        ans += merge(l, m + 1, r);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        cout << mergeSort(0, n - 1) << endl;
        a.clear();
    }
    return 0;
}