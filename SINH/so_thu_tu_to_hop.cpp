#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[16], b[16];
int cnt = 1;

int check()
{
    for (int i = 1; i <= k; i++)
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
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            if (!check())
                cnt++;
            else
            {
                cout << cnt << endl;
                break;
            }
        }
        else
            back_track(i + 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> b[i];
        }
        cnt = 1;
        back_track(1);
    }
}