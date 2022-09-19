#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> edge;
int a[1001][1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                edge.push_back({i, j});
            }
        }
    }

    int m = 1;
    for (auto x : edge)
    {
        if (x.first == m)
            cout << x.second << " ";
        else
        {
            cout << endl;
            cout << x.second << " ";
        }
        m = x.first;
    }
    return 0;
}