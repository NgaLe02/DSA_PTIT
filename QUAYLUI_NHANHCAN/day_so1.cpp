#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(11);

void outp()
{
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << "]" << endl;
}

void solve()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    outp();
    while (v.size() > 1)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i] = v[i] + v[i + 1];
        }
        v.pop_back();
        outp();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}