#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
bool unused[1005];
bool ok;

void result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

bool check()
{
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i + 1] - a[i]) == 1)
            return 0;
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
                {
                    ok = true;
                    result();
                }
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            unused[i] = true;
        ok = false;
        backtracking(1);
        if (!ok)
            cout << endl;
    }
    return 0;
}