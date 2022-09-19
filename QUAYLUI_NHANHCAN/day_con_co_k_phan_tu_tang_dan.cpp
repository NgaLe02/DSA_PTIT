#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>;

int n, k;
int a[16], x[16];

int check()
{
    for (int i = 1; i < k; i++)
    {
        if (x[i + 1] < x[i])
            return 0;
    }
    return 1;
}

void back_track(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            if (check())
            {
                for (int i = 1; i <= k; i++)
                    cout << a[x[i] - 1] << " ";
                cout << endl;
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
        a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        back_track(1);
    }
    return 0;
}