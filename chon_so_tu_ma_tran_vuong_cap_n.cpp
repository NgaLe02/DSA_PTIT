#include <bits/stdc++.h>
using namespace std;

int n, k, ok;
int a[1001], b[1001][1001];
vector<vector<int>> v;
void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}
void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
        ok = 0;
    else
    {
        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += b[i][a[i]];
    }
    if (sum == k)
        return true;
    return false;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
        }
    }
    ktao();
    ok = 1;
    vector<int> ve;
    while (ok)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
            {
                ve.push_back(a[i]);
            }
            v.push_back(ve);
            ve.clear();
        }
        sinh();
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}