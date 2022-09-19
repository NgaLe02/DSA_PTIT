#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        map<int, int> mp;
        for (int &x : a)
        {
            cin >> x;
            mp[x]++;
            ;
        }
        int check = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) != mp.end() && mp[a[i]] > 1)
            {
                cout << a[i] << endl;
                check = 1;
                break;
            }
        }
        if (!check)
            cout << "NO\n";
    }
    return 0;
}