#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v, int n)
{
    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1;
    while (l < r)
    {
        cout << v[r] << " " << v[l] << " ";
        l++;
        r--;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        solve(v, n);
    }
    return 0;
}
