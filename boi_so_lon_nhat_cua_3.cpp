#include <bits/stdc++.h>
using namespace std;

string solve(int a[], int n)
{
    sort(a, a + n);
    queue<int> q0, q1, q2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] % 3 == 0)
            q0.push(a[i]);
        else if (a[i] % 3 == 1)
            q1.push(a[i]);
        else
            q2.push(a[i]);
    }
    if (sum % 3 == 1)
    {
        if (!q1.empty())
        {
            q1.pop();
        }
        else
        {
            if (!q2.empty())
            {
                q2.pop();
            }
            else
                return "-1";
            if (!q2.empty())
            {
                q2.pop();
            }
            else
                return "-1";
        }
    }
    else if (sum % 3 == 2)
    {
        if (!q2.empty())
        {
            q2.pop();
        }
        else
        {
            if (!q1.empty())
            {
                q1.pop();
            }
            else
                return "-1";
            if (!q1.empty())
            {
                q1.pop();
            }
            else
                return "-1";
        }
    }
    int copy[n];
    int i = 0;
    while (!q0.empty())
    {
        copy[i++] = q0.front();
        q0.pop();
    }
    while (!q1.empty())
    {
        copy[i++] = q1.front();
        q1.pop();
    }
    while (!q2.empty())
    {
        copy[i++] = q2.front();
        q2.pop();
    }
    sort(copy, copy + i, greater<int>());
    string cp = "";
    for (int j = 0; j < i; j++)
    {
        cp += (copy[j] + '0');
    }
    return cp;
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
        if (solve(a, n) != "")
            cout << solve(a, n) << endl;
        else
            cout << "-1\n";
    }
    return 0;
}