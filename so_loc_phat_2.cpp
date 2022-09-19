#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    queue<string> q;
    vector<string> v;
    q.push("6");
    q.push("8");
    v.push_back("6");
    v.push_back("8");
    while (1)
    {
        string tmp = q.front();
        if (tmp.size() == n)
        {
            break;
        }
        q.pop();
        v.push_back(tmp + "6");
        v.push_back(tmp + "8");
        q.push(tmp + "6");
        q.push(tmp + "8");
    }
    cout << v.size() << endl;
    for (string x : v)
    {
        cout << x << " ";
    }
    cout << endl;
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