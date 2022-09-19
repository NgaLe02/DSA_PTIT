#include <bits/stdc++.h>
using namespace std;

void solve(int n, int s, int m)
{
    // số lương thực tối thiểu để sống qua s ngày
    int t = s * m;
    int res = 0; // số ngày ít nhất mua lương thực
    for (int i = 1; i <= s; i++)
    {
        if (i % 7 == 0) // đây là ngày chủ nhật
        {
            continue;
        }
        else
        {
            res++;
            // số lượng thực mua đã đủ để sống qua s ngày
            if (res * n >= t)
            {
                cout << res << endl;
                return;
            }
        }
    }
    cout << "-1" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        solve(n, s, m);
    }
    return 0;
}