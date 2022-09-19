#include <bits/stdc++.h>
using namespace std;
int n, k, ok, a[101], b[101], x[101];
void kt()
{
    for (int i = 1; i <= k; i++)
        a[i] = i;
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

bool check()
{
    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        x[cnt++] = b[a[i]];
    }
    for (int i = 0; i < cnt - 1; i++)
    {
        if (x[i] >= x[i + 1])
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    kt();
    ok = 1;
    int dem = 0;
    while (ok)
    {
        if (check())
            dem++;
        sinh();
    }
    cout << dem;
    return 0;
}