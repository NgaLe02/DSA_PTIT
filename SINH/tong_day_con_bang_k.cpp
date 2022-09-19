#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100], b[100];
int ok;

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
bool check()
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            s += b[i];
    }
    if (s == k)
        return true;
    return false;
}
int main()
{
    cin >> n >> k;
    ok = 1;
    b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    ktao();
    int dem = 0;
    while (ok == 1)
    {
        if (check() == true)
        {
            dem++;
            for (int i = 1; i <= n; i++)
                if (a[i] == 1)
                    cout << b[i] << " ";
            cout << endl;
        }
        sinh();
    }
    cout << dem;
    return 0;
}