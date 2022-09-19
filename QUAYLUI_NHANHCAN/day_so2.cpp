#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(11);
vector<vector<int>> ve;

void outp()
{
    for (int i = ve.size() - 1; i >= 0; i--)
    {
        cout << "[";
        for (int j = 0; j < ve[i].size(); j++)
        {
            cout << ve[i][j];
            if (j != ve[i].size() - 1)
                cout << " ";
            else
                cout << "]";
        }
        cout << " ";
    }
    cout << endl;
}

void solve()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ve.push_back(v);
    while (v.size() > 1)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i] = v[i] + v[i + 1];
        }
        v.pop_back();
        ve.push_back(v);
    }
    outp();
    ve.clear();
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