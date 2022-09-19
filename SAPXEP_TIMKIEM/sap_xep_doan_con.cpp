#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n], copy[n], dem = 0;
        vector<int> mem;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            copy[i] = a[i];
        }
        sort(a, a + n);
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            s1 += a[i];
            s2 += copy[i];
            if (s1 == s2)
            {
                ++dem;
                mem.push_back(i + 1);
            }
        }
        cout << dem << endl;
        for (int x : mem)
            cout << x << " ";
        cout << endl;
    }
}
