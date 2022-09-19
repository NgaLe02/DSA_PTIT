#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int a[21], m, n, dem;

int check()
{
    if (a[1] == 0)
        return 0;
    int dem = 0;
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == 2)
            dem++;
    }
    if (dem > m / 2)
        return 1;
    return 0;
}

void in()
{
    for (int i = 1; i <= m; i++)
        cout << a[i];
    cout << " ";
}
void sinh(int i, int &dem)
{
    for (int j = 0; j <= 2; j++)
    {
        if (dem == n)
            break;
        a[i] = j;
        if (i == m)
        {
            if (check())
            {
                in();
                dem++;
            }
        }
        else
            sinh(i + 1, dem);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int dem = 0;
      //2  m = 1;
        for (int i = 1; i < 10; i++)
        {
            m = i;
            sinh(1, dem);
            if (dem >= n)
                break;
        }
        cout << endl;
    }
    return 0;
}
