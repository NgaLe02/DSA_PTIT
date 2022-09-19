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
        set<int> s;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        sort(a, a + n);
        int max = a[n - 1];
        int min = a[0];
        int dem = max - min + 1;
        cout << dem - s.size() << endl;
    }
    return 0;
}