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
        }
        int max = INT_MIN;
        for (auto x : mp)
        {
            if (x.first > max && x.second > n / 2)
            {
                max = x.first;
            }
        }
        if (max == INT_MIN)
        {
            cout << "NO\n";
        }
        else
            cout << max << endl;
    }
}