#include <bits/stdc++.h>
using namespace std;

// cho thời gian bắt đầu, kết thúc vào 1 pair
// đẩy hết vào vector
// sắp xếp vector theo thứ tự tăng dần của thời gian lết thúc
// tạo biến đếm
// nếu thời gian công việc bắt đầu sau >= thơ gian kết thúc công việc trước
// tăng biến đếm
typedef pair<int, int> pi;
int cmp(pi a, pi b)
{
    return a.second < b.second;
}
void solve(int a[], int b[], int n)
{
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = a[i];
        v[i].second = b[i];
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 1;
    int mem = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= mem)
        {
            mem = v[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        solve(a, b, n);
    }
}