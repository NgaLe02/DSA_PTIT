#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> v;

void xau(int i)
{
    for (int j = 6; j <= 8; j += 2)
    {
        a[i] = j;
        if (i == n - 1)
        {
            v.push_back(a);
        }
        else
            xau(i + 1);
    }
}

void in()
{
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
        cout << " ";
    }
    cout << endl;
    v.clear();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        xau(0);
        in();
    }
    return 0;
}