#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    queue<string> q;
    q.push("4");
    q.push("5");
    vector<string> v;
    v.push_back("4");
    v.push_back("5");
    while (v.size() < n)
    {
        string top = q.front();
        q.pop();
        q.push(top + "4");
        v.push_back(top + "4");
        q.push(top + "5");
        v.push_back(top + "5");
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i];
        for (int j = v[i].size() - 1; j >= 0; j--)
            cout << v[i][j];
        cout << " ";
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
    return 0;
}