#include <bits/stdc++.h>
using namespace std;

int Ugly(int n)
{
    if (n >= 1 && n <= 5)
        return n;
    set<int> s;
    s.insert(1);
    n--;
    while (n--)
    {
        auto it = s.begin();
        // lấy phần tử ban đầu của set
        int tmp = *it;
        // xoá phần tử
        s.erase(it);
        // chèn tất cả các lựa chọn khác
        s.insert(tmp * 2);
        s.insert(tmp * 3);
        s.insert(tmp * 5);
    }
    // đây là số xấu thứ n
    return *s.begin();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << Ugly(n) << endl;
    }
    return 0;
}