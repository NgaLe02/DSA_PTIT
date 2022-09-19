#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    int k = 0;
    while (k < t)
    {
        string s;
        cin >> s;
        vector<int> v;
        int x = 1, j = 0;
        v.push_back(x);
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'I')
            {
                v.push_back(++x);
                j = v.size() - 1;
            }
            else
                v.insert(v.begin() + j, ++x);
        }
        cout << "Test ";
        cout << k + 1 << ": ";
        for (int i : v)
            cout << i;
        cout << endl;
        k++;
    }
}
