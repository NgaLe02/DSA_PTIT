#include <bits/stdc++.h>
using namespace std;

int n;
int a[11], b[11];
bool unused[11];
int cnt = 1;

int check()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
void back_track(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (unused[j] == true)
        {
            a[i] = j;
            unused[j] = false;
            if (i == n)
            {
                if (!check())
                {
                    cnt++;
                }
                else
                {
                    cout << cnt << endl;
                    break;
                }
            }
            else
                back_track(i + 1);
            unused[j] = true;
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
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        memset(unused, true, sizeof(unused));
        cnt = 1;
        back_track(1);
    }
}