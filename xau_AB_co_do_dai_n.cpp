#include <bits/stdc++.h>
using namespace std;

int n, k, ok;
char a[11];

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 'A';
    }
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 'B')
    {
        a[i] = 'A';
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 'B';
}

bool check()
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            dem++;
        }
    }
    if (dem == k)
        return true;
    return false;
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