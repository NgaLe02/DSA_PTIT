#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, a[101], cnt;
int store[101];

int check()
{
    for (int i = 1; i < n; i++)
    {
        if (a[i + 1] < a[i])
            return 0;
    }
    return 1;
}
void sinh(int i)
{
    for (int j = 1; j <= 9; j++)
    {
        a[i] = j;
        if (i == n)
        {
            if (check())
                cnt++;
        }
        else
            sinh(i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    memset(store, 0, sizeof(store));
    store[1] = 10;
    store[2] = 55;
    while (t--)
    {
        cin >> n;
        if (n <= 2)
            cout << store[n] << endl;
        else
        {
            for (int i = 3; i <= n; i++)
            {
                if (store[i] == 0)
                {
                    cnt = 0;
                    sinh(1);
                    store[i] = cnt + store[i - 1];
                }
            }
            cout << store[n] << endl;
        }
    }
    return 0;
}