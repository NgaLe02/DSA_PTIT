#include <bits/stdc++.h>
using namespace std;

int n, a[100], k;
vector<vector<int>> res;

void inp()
{
    cin >> n;
    res.clear();
}

void ql(int sum, int pos, int cnt)
{
    if (sum == n)
    {
        vector<int> tmp(a, a + cnt);
        res.push_back(tmp);
        return;
    }
    for (int j = pos; j >= 1; j--)
    {
        if (sum + j <= n)
        {
            a[cnt] = j;
            ql(sum + j, j, cnt + 1);
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
        ql(0, n, 0);
        cout << res.size() << endl;
        for (auto it : res)
        {
            cout << "(";
            for (int i = 0; i < it.size(); i++)
            {
                cout << it[i];
                if (i == it.size() - 1)
                {
                    cout << ") ";
                }
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}
