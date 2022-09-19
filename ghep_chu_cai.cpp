#include <bits/stdc++.h>
using namespace std;

int n, k;
char c;
int a[1005];
bool unused[1005];

void result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << (char)(a[i] + 64);
    }
    cout << endl;
}

bool check()
{
    if (n < 5)
    {
        for (int i = 2; i < n; i++)
        {
            if (a[i] == 1)
                return 0;
        }
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (a[i] == 1 || a[i] == 5)
            {
                if (a[i - 1] != 1 && a[i - 1] != 5)
                    if (a[i + 1] != 1 && a[i + 1] != 5)
                        return 0;
            }
        }
    }
    return 1;
}

void backtracking(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (unused[j] == true)
        {
            a[i] = j;
            unused[j] = false; // dã được sử dụng
            if (i == n)
            {
                if (check())
                    result();
            }
            else
            {
                backtracking(i + 1);
            }
            unused[j] = true; // backtrack: trả lại giá trị cho j;
        }
    }
}

int main()
{
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++)
        unused[i] = true;
    backtracking(1);
    return 0;
}