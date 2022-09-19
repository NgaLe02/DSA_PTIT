#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            ans++;
        else
        {
            cout << ans << endl;
            return;
        }
    }
    // nếu mảng toàn số 1 thì sẽ ko thực hiện lệnh 13, 14
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &x : a)
            cin >> x;
        solve(a, n);
    }
    return 0;
}