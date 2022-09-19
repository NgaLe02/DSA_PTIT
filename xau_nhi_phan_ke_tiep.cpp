#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];
int ok;

void sinh(string &s)
{
    int i = s.length() - 1;
    while (i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i == -1)
        ok = 0;
    else
        s[i] = '1';
}
int main()
{
    cin >> n;
    while (n-- > 0)
    {
        string s;
        cin >> s;
        sinh(s);
        for (int i = 0; i < s.length(); i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}