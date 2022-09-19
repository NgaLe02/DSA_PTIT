#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int b[], int n, int m)
{
    // sort(a, a + n);
    // sort(b, b + m);
    set<int> se, se1, se2;
    for (int i = 0; i < n; i++)
    {
        se1.insert(a[i]);
        se.insert(a[i]);
    }
    for (int j = 0; j < m; j++)
    {
        se2.insert(b[j]);
        se.insert(b[j]);
    }
    for (int x : se)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x : se1)
    {
        if (se2.find(x) != se2.end())
        {
            cout << x << " ";
        }
    }
    cout << endl;
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
            cin >> a[i];
        for (int j = 0; j < m; j++)
            cin >> b[j];
        solve(a, b, n, m);
    }
    return 0;
}