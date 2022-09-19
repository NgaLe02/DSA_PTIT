#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    queue<string> q;
    q.push("9");
    if (9 % n == 0)
    {
        cout << 9 << endl;
        return;
    }
    while (1)
    {
        string tmp = q.front();
        q.pop();
        string t = tmp + "0";
        if ((stoll(t)) % n == 0)
        {
            cout << t << endl;
            return;
        }
        q.push(t);
        t = tmp + "9";
        if ((stoll(t)) % n == 0)
        {
            cout << t << endl;
            return;
        }
        q.push(t);
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
}