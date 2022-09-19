#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int cmp(int a, int b)
{
    if (m[a] != m[b])
        return m[a] > m[b];
    return a < b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a + n, cmp);
        for (int x : a)
        {
            cout << x << " ";
        }
        cout << endl;
        m.clear();
    }
}