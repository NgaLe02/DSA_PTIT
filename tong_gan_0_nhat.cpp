#include <bits/stdc++.h>
using namespace std;
// O(n*n)
void solve1(int a[], int n)
{
    int mem = INT_MAX, x;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            x = a[i] + a[j];
            if (abs(x) < abs(mem))
                mem = x;
        }
    }
    cout << mem << endl;
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
            cin >> a[i];
        solve1(a, n);
    }
    return 0;
}