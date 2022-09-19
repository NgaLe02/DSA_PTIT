#include <bits/stdc++.h>
using namespace std;

int n, k, ok;
char a[17];

void ktao()
{
    a[1] = 'H';
    for (int i = 2; i <= n; i++)
    {
        a[i] = 'A';
    }
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 'H')
    {
        a[i] = 'A';
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 'H';
}

bool check()
{
    if (a[1] == 'A' || a[n] == 'H')
        return false;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 'H' && a[i] == a[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ok = 1;
        ktao();
        while (ok)
        {
            if (check())
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i];
                }
                cout << endl;
            }

            sinh();
        }
    }
}