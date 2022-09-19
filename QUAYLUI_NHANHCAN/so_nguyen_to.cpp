#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

// Ý tưởng: 
vector<vector<int>> res;
vector<int> tmp, ngto;
int a[1001];
int n, p, s, k;

int prime[201];
void sieve()
{
    for (int i = 0; i <= 201; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= 201; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= 201; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void solve()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += ngto[a[i] - 1];
    }
    if (sum == s)
    {
        for (int i = 1; i <= n; i++)
        {
            tmp.push_back(ngto[a[i] - 1]);
        }
        res.push_back(tmp);
        tmp.clear();
    }
}

void to_hop(int i)
{
    for (int j = a[i - 1] + 1; j <= k - n + i; j++)
    {
        a[i] = j;
        if (i == n)
        {
            solve();
        }
        else
            to_hop(i + 1);
    }
}

void in()
{
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    res.clear();
    ngto.clear();
}
int main()
{
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        cin >> n >> p >> s;
        k = 0;
        for (int i = p + 1; i <= s; i++)
        {
            if (prime[i])
            {
                k++;
                ngto.push_back(i);
            }
        }
        to_hop(1);
        in();
    }
    return 0;
}