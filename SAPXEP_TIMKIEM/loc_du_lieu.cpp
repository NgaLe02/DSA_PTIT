#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] > 0)
        {
            cout << v[i] << " ";
            mp[v[i]] = 0;
        }
    }
    return 0;
}