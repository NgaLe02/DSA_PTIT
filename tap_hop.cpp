#include <bits/stdc++.h>
using namespace std;

int n, k, s, ans = 0;
int x[100];

void input()
{
    cin >> n >> k >> s;
}

void back_track(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            int sum = 0;
            for (int j = 1; j <= k; j++)
            {
                sum += x[j];
            }
            if (sum == s)
                ++ans;
        }
        else
            back_track(i + 1);
    }
}

int main()
{
    while (true)
    {
        input();
        if (n + k + s == 0)
            break;
        ans = 0;
        back_track(1);
        cout << ans << endl;
    }
}