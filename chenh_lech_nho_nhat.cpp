#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n)
{
    sort(a, a + n);
    int min = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] < min)
        {
            min = a[i + 1] - a[i];
        }
    }
    cout << min << endl;
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
        for (int &x : a)
            cin >> x;
        solve(a, n);
    }
    return 0;
}