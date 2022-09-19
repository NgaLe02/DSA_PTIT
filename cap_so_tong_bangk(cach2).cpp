#include <bits/stdc++.h>
using namespace std;

void solve1(int a[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += m[k - a[i]];
        // Nếu k - a[i] = a[i] ta phải trừ đi TH chính a[i] + a[i] = k
        // vì ta chỉ đếm a[i] + a[j] = k với j khác i
        // vd : 1 1 1  k = 2, mp[1] = 3
        // i = 0, ans = 3 nhưng phải trừ đi trường hợp a[0] + a[0] = 2
        if (k - a[i] == a[i]) // a[i] + a[i] == k
            ans--;
    }
    cout << ans / 2 << endl;
}

void solve2(int a[], int n, int k)
{
    // vd: 1 5 4 1 2 k =9
    // i = 0: ans = 0, m[1] = 1 // i = 1: ans = 0, m[5] = 1;
    // i = 2: ans +=m[5] = 1, m[4] = 1;
    // v.v.v
    unordered_map<int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += m[k - a[i]];
        m[a[i]]++;
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve1(a, n, k);
    }
    return 0;
}