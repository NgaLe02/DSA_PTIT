#include <bits/stdc++.h>
using namespace std;

set<string> se;
int a[11];

void in()
{
    for (int i = 1; i <= 8; i++)
    {
        cout << a[i];
        if (i == 2 || i == 4)
            cout << "/";
    }
    cout << endl;
}
int check()
{
    if (a[1] == 0 && a[2] == 0)
        return 0;
    if (a[3] == 2)
        return 0;
    if (a[3] == 0 && a[4] == 0)
        return 0;
    if (a[5] == 0)
        return 0;
    return 1;
}
void backtrack(int i)
{
    for (int j = 0; j <= 2; j += 2)
    {
        a[i] = j;
        if (i == 8)
        {
            if (check())
                in();
        }
        else
            backtrack(i + 1);
    }
}
int main()
{
    backtrack(1);
    return 0;
}