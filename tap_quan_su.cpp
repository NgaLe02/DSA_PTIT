#include <bits/stdc++.h>
using namespace std;

int n, k, ok, dem;
int a[101], b[101];

void sinh(int a[])
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
        ok = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ok = 1;
        set<int> se;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            se.insert(a[i]);
        }
        sinh(a);
        dem = 0;
        if (ok == 0)
            dem = k;
        else
        {
            for (int i = 1; i <= k; i++)
            {
                if (se.find(a[i]) == se.end())
                {
                    dem++;
                }
            }
        }
        cout << dem << endl;
    }
    return 0;
}