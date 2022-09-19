#include <bits/stdc++.h>
using namespace std;

int n, a[100], x[100], k, res = 0;
int c[100][100], cmin = INT_MAX, fopt = INT_MAX;
bool used[101];

void inp()
{
    memset(used, false, sizeof(used));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 1)
                cmin = min(cmin, c[i][j]); // chi phi nho nhat
        }
    }
}

void ql(int i)
{
    for (int j = 2; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = true;
            x[i] = j; // thanh pho lua chon di thu i la thanh pho j
            res += c[x[i]][x[i - 1]];
            if (i == n)
            {
                fopt = min(fopt, res + c[x[n]][1]);
            }
            else if (res + cmin * (n - i + 1) < fopt)
            {
                ql(i + 1);
            }
            used[j] = false;
            res -= c[x[i]][x[i - 1]];
        }
    }
}

int main()
{
    inp();
    x[1] = 1;
    ql(2);
    cout << fopt << endl;
}