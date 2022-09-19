#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    queue<long long> q;
    q.push(9);
    while (1)
    {
        long x = q.front();
        if (x % n == 0)
        {
            cout << x << endl;
            break;
        }
        else
        {
            q.pop();
            q.push(x * 10);
            q.push(x * 10 + 9);
        }
    }
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