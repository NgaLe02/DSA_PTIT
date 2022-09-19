#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m], c[n + m];
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            c[k++] = a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            c[k++] = b[i];
        }
        sort(c, c + n + m);
        for (int i = 0; i < k; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
    }
}