#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n]; // đánh dấu vị trí số chẳn, số lẻ
    // b[i] = 0, vị trí số chẵn
    // b[i] = 1, vị trí số lẻ
    vector<int> c, l;
    // c: chứa số chẵn
    // l: chứa số lẻ
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[i] = 0;
            c.push_back(a[i]);
        }
        else
        {
            b[i] = 1;
            l.push_back(a[i]);
        }
    }
    sort(c.begin(), c.end());
    sort(l.begin(), l.end(), greater<int>());
    int m = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            cout << c[m++] << " ";
        }
        else
            cout << l[k++] << " ";
    }
    cout << endl;
    return 0;
}