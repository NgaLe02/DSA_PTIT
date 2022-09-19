#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll convert(string a)
{
    ll res = 0;
    for (int i = 0; i < a.length(); i++)
    {
        res = res * 2 + a[i] - '0';
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << convert(a) * convert(b) << endl;
    }
    return 0;
}