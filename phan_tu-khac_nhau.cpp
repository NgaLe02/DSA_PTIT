#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int b[], int n)
{
    int i = 0, j = 0;
    while (i < n && j < n - 1)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << n << endl;
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
        int b[n - 1];
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        solve(a, b, n);
    }
    return 0;
}