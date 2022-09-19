#include <bits/stdc++.h>
using namespace std;

int x, ok;
string s;

void hoanvi()
{
    int i = s.length() - 2;
    while (i >= 0 && s[i] >= s[i + 1])
    {
        i--;
    }
    if (i == -1)
        ok = 0;
    else
    {
        int j = s.length() - 1;
        while (s[i] - '0' >= s[j] - '0')
        {
            j--;
        }
        swap(s[i], s[j]);
        sort(s.begin() + i + 1, s.end());
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ok = 1;
        cin >> x >> s;
        hoanvi();
        if (!ok)
            cout << x << " BIGGEST" << endl;
        else
            cout << x << " " << s << endl;
    }
}