#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n, int k)
{
    // dq chứa các index của các phần tử trong mảng
    //  a[dq.back()] -> a[dq.front()] theo thứ tự tăng dần
    // dq chỉ chứa các index của cửa sổ hiện tại cần tính
    deque<int> dq;
    // cửa sổ đầu tiên
    for (int i = 0; i < k; i++)
    { // 1
        // nếu phần tử a[i] hiện tại lớn hơn các phần tử trước đó
        // thì loại bỏ các phần tử trước đó đi
        // ta chỉ lưu index mà a[index] lớn nhất
        while (!dq.empty() && a[i] >= a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        // đây là phần tử lớn nhất của cửa sổ trước đó
        cout << a[dq.front()] << " ";
        // loại bỏ các index ko nằm trong cửa sổ hiện tại
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        // tương tự như dòng lệnh 12
        while (!dq.empty() && a[i] >= a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << a[dq.front()] << endl;
    dq.clear();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int &x : a)
            cin >> x;
        solve(a, n, k);
    }
    return 0;
}