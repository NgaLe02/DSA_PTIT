#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int sum)
{
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (a[i] + a[j] + a[k] == sum)
            {
                return 1;
            }
            else if (a[i] + a[j] + a[k] > sum)
            {
                k--;
            }
            else
                j++;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        int a[n];
        for (int &x : a)
            cin >> x;
        if (solve(a, n, sum))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}