#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>;

// Approach: Dùng sinh xâu nhị phân
// Nếu x[i] = 1 thì ta xét a[i - 1]
// do x[1---n] còn a[0...n-1];

int x[16], n, a[16];
vector<vector<int>> res;

int check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
            sum += a[i - 1];
    }
    if (sum % 2 == 1)
        return 1;
    return 0;
}

void sinh(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            if (check())
            {
                vector<int> temp;
                for (int i = 1; i <= n; i++)
                {
                    if (x[i] == 1)
                        temp.push_back(a[i - 1]);
                }
                res.push_back(temp);
            }
        }
        else
            sinh(i + 1);
    }
}

void in()
{
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
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<int>());
        sinh(1);
        in();
    }
    return 0;
}