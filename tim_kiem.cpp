#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        set<int> se;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            se.insert(a[i]);
        }
        if (se.find(x) != se.end())
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
}