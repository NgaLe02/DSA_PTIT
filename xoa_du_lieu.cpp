#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int x;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != x)
        {
            cout << v[i] << " ";
        }
    }
    return 0;
}