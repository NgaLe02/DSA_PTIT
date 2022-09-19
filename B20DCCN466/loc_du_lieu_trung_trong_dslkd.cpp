#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int x;
        cin >> x;
        if (s.find(x) == s.end())
        {
            cout << x << " ";
            s.insert(x);
        }
    }
    return 0;
}