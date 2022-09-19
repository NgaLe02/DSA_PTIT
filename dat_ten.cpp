#include <bits/stdc++.h>
using namespace std;
int n, k, pos = -1, gt[20];
vector<string> s;
string a[20];
void sinh(int i)
{
    for (int j = 0; j < n; ++j)
        if (j > pos && s[j] > a[i - 1])
        {
            pos = j;
            a[i] = s[j];
            if (i == k)
            {
                for (int h = 1; h <= i; ++h)
                    cout << a[h] << " ";
                cout << endl;
            }
            else
                sinh(i + 1);
            pos = -1;
        }
}
int main()
{
    cin >> n >> k;
    a[0] = " ";
    set<string> se;
    while (n--)
    {
        string x;
        cin >> x;
        se.insert(x);
    }
    for (auto x : se)
        s.push_back(x);
    n = se.size();
    sinh(1);
}