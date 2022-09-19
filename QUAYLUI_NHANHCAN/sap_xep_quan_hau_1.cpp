#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int cot[100], xuoi[100], nguoc[100];

void backtrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 1 & xuoi[i - j + n] == 1 & nguoc[i + j - 1] == 1)
        {
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            if (i == n)
            {
                ++cnt;
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
    while (t--)
    {
        cin >> n;
        for (int i = 1; i < 100; i++)
        {
            cot[i] = xuoi[i] = nguoc[i] = 1;
        }
        cnt = 0;
        backtrack(1);
        cout << cnt << endl;
    }
}