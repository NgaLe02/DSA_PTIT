#include <bits/stdc++.h>
using namespace std;

string s;

void sinh()
{
    int i = s.length() - 1;
    while (i >= 0 && s[i] == '0')
    {
        s[i] = '1';
        i--;
    }
    if (i == -1)
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = '1';
        }
    else
        s[i] = '0';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        sinh();
        for (int i = 0; i < s.length(); i++)
            cout << s[i];
        cout << endl;
    }

    return 0;
}