#include <bits/stdc++.h>
using namespace std;

int n;
int a[16];

int check()
{
    if (a[1] == 6 || a[n] == 8)
        return 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] == 8 && a[i] == a[i + 1])
            return 0;
    }
    for (int i = 1; i <= n - 3; i++)
    {
        if (a[i] == 6 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3])
            return 0;
    }
    return 1;
}

void back_track(int i)
{
    for (int j = 6; j <= 8; j += 2)
    {
        a[i] = j;
        if (i == n)
        {
            if (check())
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i];
                }
                cout << endl;
            }
        }
        else
            back_track(i + 1);
    }
}
int main()
{
    cin >> n;
    back_track(1);
    return 0;
}