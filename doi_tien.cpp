#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
void solve(int n)
{
    int ans = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (n >= a[i])
        {
            ans += n / a[i];
            n %= a[i];
        }
    }
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
        solve(n);
    }
    return 0;
}