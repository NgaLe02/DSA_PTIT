#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[100][100], b[100];
int cot[100], xuoi[100], nguoc[100];

void inp()
{
    n = 8;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < 100; i++)
    {
        cot[i] = xuoi[i] = nguoc[i] = 1;
    }
}
void backtrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 1 & xuoi[i - j + n] == 1 & nguoc[i + j - 1] == 1)
        {
            // con hậu ở hàng i nằm ở cột j
            b[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            if (i == n)
            {
                int sum = 0;
                for (int k = 1; k <= 8; k++)
                {
                    sum += a[k][b[k]];
                }
                ans = max(ans, sum);
            }
            else
                backtrack(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int test = 1;
    while (t--)
    {
        inp();
        ans = 0;
        backtrack(1);
        cout << "Test " << test << ": ";
        cout << ans << endl;
        test++;
    }
}
