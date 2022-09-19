#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> q;
        vector<string> v;
        q.push("6");
        v.push_back("6");
        q.push("8");
        v.push_back("8");
        while (1)
        {
            string a = q.front();
            if (a.length() == n)
                break;
            q.pop();
            q.push(a + "6");
            q.push(a + "8");
            v.push_back(a + "6");
            v.push_back(a + "8");
        }
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for (string x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}