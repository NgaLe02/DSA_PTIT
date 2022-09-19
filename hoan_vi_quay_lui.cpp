#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1005];
bool unused[1005];

void result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void backtracking(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (unused[j] == true)
        {
            a[i] = j;
            unused[j] = false; // dã du?c s? d?ng
            if (i == n)
            {
                result();
            }
            else
            {
                backtracking(i + 1);
            }
            unused[j] = true; // backtrack: tr? l?i giá tr? cho j;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        unused[i] = true;
    backtracking(1);
    return 0;
}