#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, k;
vector<string> v;

int main()
{
    cin >> n >> k;
    v.réi
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cin.ignore();
    }
    int cnt = 0;
    for (int i = 0; i < v.size() - k; i++)
    {
        for (int j = i + k; j < n; j++)
        {
            if (v[i].size() == v[j].size())
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
