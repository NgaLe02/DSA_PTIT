#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    vector<int> ve;
    ve.push_back(0);
    ve.push_back(a[0]);
    v.push_back(ve);
    ve.clear();
    for (int i = 1; i < n; i++)
    {
        ve.push_back(i);
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        for (int j = 0; j <= i; j++)
        {
            ve.push_back(a[j]);
        }
        v.push_back(ve);
        ve.clear();
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << "Buoc " << v[i][0] << ": ";
        for (int j = 1; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}