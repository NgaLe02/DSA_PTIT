#include <bits/stdc++.h>
using namespace std;
int x;
int cmp(int a, int b)
{
    return (abs(a - x) < abs(b - x));
}
void solve(int a[], int n, int x)
{
    stable_sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(a, n, x);
    }
    return 0;
}
