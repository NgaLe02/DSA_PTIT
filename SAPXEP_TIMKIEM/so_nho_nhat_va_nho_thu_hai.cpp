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
        for (int &x : a)
            cin >> x;
        sort(a, a + n);
        int min2 = a[0];
        int min1 = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > min1)
            {
                min2 = a[i];
                break;
            }
        }
        if (min2 == min1)
            cout << "-1" << endl;
        else
            cout << min1 << " " << min2 << endl;
    }
}