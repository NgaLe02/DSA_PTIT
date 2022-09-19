#include <bits/stdc++.h>
using namespace std;
// chẵn : tăng
// lẻ : giảm
void solve(int a[], int n)
{
    vector<int> c, l;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            c.push_back(a[i]);
        else
            l.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    sort(l.begin(), l.end(), greater<int>());
    int j = 0;
    for (int i = 0; i < c.size(); i++)
    {
        a[j] = c[i];
        j += 2;
    }
    j = 1;
    for (int i = 0; i < l.size(); i++)
    {
        a[j] = l[i];
        j += 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    solve(a, n);
    return 0;
}