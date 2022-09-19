#include <bits/stdc++.h>
using namespace std;
int s, n, x[100], a[100], k, ok;
bool check()
{
    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum += x[a[i]];
    return sum == s;
}
void next()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
        --i;
    if (i == 0)
        ok = false;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}
void inp()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
    {
        k = i;
        ok = 1;
        for (int j = 1; j <= k; j++)
            a[j] = j;
        while (ok)
        {
            if (check())
            {
                cout << i << "\n";
                return;
            }
            next();
        }
    }
    cout << "-1\n";
}
int main()
{
    inp();
}