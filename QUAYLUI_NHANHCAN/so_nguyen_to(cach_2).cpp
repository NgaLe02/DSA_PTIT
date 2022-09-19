#include <bits/stdc++.h>
using namespace std;

int nt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

int p, s, n, used[100], a[100];
vector<int> ngto;
vector<vector<int>> res;

void sang()
{
    for (int i = p + 1; i <= s; i++)
    {
        if (nt(i))
            ngto.push_back(i);
    }
}

void ql(int sum, int cnt, int pos)
{
    if (sum == s && cnt == n)
    {
        vector<int> tmp(a, a + n);
        res.push_back(tmp);
        return;
    }
    for (int j = pos; j < ngto.size(); j++)
    {
        if (!used[j] && sum + ngto[j] <= s)
        {
            used[j] = true;
            a[cnt] = ngto[j];
            ql(sum + ngto[j], cnt + 1, j);
            used[j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> s;
        ngto.clear();
        memset(used, false, sizeof(used));
        res.clear();
        sang();
        ql(0, 0, 0);
        cout << res.size() << endl;
        for (auto it : res)
        {
            for (int x : it)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}