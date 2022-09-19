#include <bits/stdc++.h>
using namespace std;

int n, k, ok, cnt;
int a[1005];
void backtracking(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
        else
            backtracking(i + 1);
    }
}

int main()
{
    cin >> n >> k;
    backtracking(1);
    return 0;
}