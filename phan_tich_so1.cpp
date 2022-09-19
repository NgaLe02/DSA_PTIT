#include <bits/stdc++.h>
using namespace std;

int n, ok, cnt;
int a[11];

void ktao()
{
    cnt = 1;
    a[1] = n;
}

void sinh()
{
    int i = cnt;
    while (i >= 1 && a[i] == 1)
    {
        i--;
    }
    if (i == 0)
        ok = 0;
    else
    {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];
        if (q)
        {
            for (int j = 1; j <= q; j++)
            {
                a[i + j] = a[i];
            }
            cnt += q;
        }
        if (r)
        {
            a[cnt + 1] = r;
            cnt++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ktao();
        ok = 1;
        while (ok)
        {
            cout << "(";
            for (int i = 1; i < cnt; i++)
            {
                cout << a[i] << " ";
            }
            cout << a[cnt];
            cout << ")"
                 << " ";
            sinh();
        }
        cout << endl;
    }
    return 0;
}