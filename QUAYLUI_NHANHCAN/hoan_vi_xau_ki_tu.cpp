#include <bits/stdc++.h>
using namespace std;

string s;
int x[11], n;
bool check[11];

void in()
{
    for (int i = 1; i <= n; i++)
    {
        char a = x[i] + 16 + '0';
        cout << a;
    }
    cout << " ";
}

void back_track(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (check[j] == true)
        {
            check[j] = false;
            x[i] = j;
            if (i == n)
                in();
            else
                back_track(i + 1);
            check[j] = true;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.length();
        for (int i = 1; i <= n; i++)
        {
            check[i] = true;
        }
        back_track(1);
        cout << endl;
    }
}