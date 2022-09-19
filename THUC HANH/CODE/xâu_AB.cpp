#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, a[101], dem;

void sinh(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 0)
                    cout << 'A';
                else
                    cout << 'B';
            }
            dem++;
            if (dem < (int)pow(2, n))
                cout << ",";
        }
        else
            sinh(i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        dem = 0;
        cin >> n;
        sinh(1);
        cout << endl;
    }
    return 0;
}