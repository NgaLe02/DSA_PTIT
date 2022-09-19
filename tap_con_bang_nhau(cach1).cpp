#include <bits/stdc++.h>
using namespace std;

// Partition Problem : Recursion
bool subSum(int a[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    if (a[n - 1] > sum)
    {
        return subSum(a, n - 1, sum);
    }
    return subSum(a, n - 1, sum) || subSum(a, n - 1, sum - a[n - 1]);
}

bool findTheSub(int a[], int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    if (sum % 2 == 1)
        return false;
    return subSum(a, n, sum / 2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (findTheSub(a, n))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}