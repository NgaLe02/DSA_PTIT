#include <bits/stdc++.h>
using namespace std;

int n, k, a[1001], ok = 1;

string s;

void khoitao()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
        s += a[i] + '0';
    }
    // v.push_back(s);
}

void sinh()
{
    int i = k;
    while (a[i] == a[i - 1] + 1)
    {
        i--;
    }
    if (i == 0)
    {
        for (int j = k; j >= 1; j--)
        {
            a[j] = n - k + j;
        }
    }
    else
    {
        a[i]--;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = n - k + j;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        sinh();
    }
    return 0;
}