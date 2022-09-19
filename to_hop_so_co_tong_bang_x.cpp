#include <bits/stdc++.h>
using namespace std;

int n, k, ok = 0;
int a[100], x[100];
vector<vector<int>> res;

void inp()
{
    cin >> n >> k;
    res.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n);
}

void ql(int sum, int cnt, int pos)
{
    if (sum == k)
    {
        vector<int> tmp(x, x + cnt);
        res.push_back(tmp);
        return;
    }
    for (int j = pos; j <= n; j++)
    {
        if (a[j] + sum <= k)
        {
            x[cnt] = a[j];
            ql(sum + a[j], cnt + 1, j);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        ql(0, 0, 1);
        if (res.size() == 0)
            cout << "-1";
        else
        {
            cout << res.size() << " ";
            for (auto it : res)
            {
                cout << "{";
                for (int i = 0; i < it.size(); i++)
                {
                    cout << it[i];
                    if (i == it.size() - 1)
                    {
                        cout << "}";
                    }
                    else
                        cout << " ";
                }
            }
        }
        cout << endl;
    }
}