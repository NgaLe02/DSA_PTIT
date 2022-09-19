#include <bits/stdc++.h>
using namespace std;
// Chỉ đúng vs mảng có các phần tử khác nhau
// Tao một một vetor of pair:
// first of pair: value of array
// second of pảir: index  of element in array
// sort vector of pair according to first of pair
int swap(int a[], int n)
{
    vector<pair<int, int>> ve(n);
    for (int i = 0; i < n; i++)
    {
        ve[i].first = a[i];
        ve[i].second = i;
    }
    sort(ve.begin(), ve.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ve[i].second == i)
        {
            continue;
        }
        else
        {
            swap(ve[i].first, ve[ve[i].second].first);
            swap(ve[i].second, ve[ve[i].second].second);
        }
        if (i != ve[i].second)
            i--;
        cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << swap(a, n) << endl;
    }
}