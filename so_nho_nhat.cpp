#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d)
{
    if (s == 0)
    {
        if (d == 1)
        {
            cout << "0" << endl;
            return;
        }
        else
        {
            cout << "-1" << endl;
            return;
        }
    }
    if (s > 9 * d)
    {
        cout << "-1\n";
        return;
    }
    int t[d];
    s--;
    for (int i = d - 1; i >= 1; i--)
    {
        if (s > 9)
        {
            t[i] = 9;
            s -= 9;
        }
        else
        {
            t[i] = s;
            s = 0;
        }
    }
    t[0] = s + 1;
    for (int i = 0; i < d; i++)
    {
        cout << t[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, d;
        cin >> s >> d;
        solve(s, d);
    }
    return 0;
}