#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int b[], int c[], int n, int m, int k)
{
    int i = 0, j = 0, l = 0;
    int ok = 0;
    while (i < n && j < m && l < k)
    {
        if (a[i] == b[j] && b[j] == c[l])
        {
            cout << a[i] << " ";
            ok = 1;
            i++;
            j++;
            l++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < c[l])
        {
            j++;
        }
        else
            l++;
    }
    if (!ok)
    {
        cout << "NO";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m], c[k];
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        for (int &x : c)
            cin >> x;
        solve(a, b, c, n, m, k);
    }
    return 0;
}