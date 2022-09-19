#include <bits/stdc++.h>
using namespace std;
;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            while (a[i] > 0)
            {
                s.insert(a[i] % 10);
                a[i] /= 10;
            }
        }
        for (int x : s)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}