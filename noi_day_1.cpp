#include <bits/stdc++.h>
using namespace std;

// 4 3 2 6
// nối 2 vs 3 dk dây độ dài bằng 5: cost = 2 + 3 = 5;
// 4 5 6, nối 4 vs 5 dk dây độ dài bằng 9 : cost  = 5 + ( 4 + 5) = 14;
// 9 6 , nối 14 vs 6 : cost = 14 + (9 + 6) = 29;
typedef long long ll;

ll cost(int a[], int n)
{
    // hàng đợi ưu tien sắp xếp theo thứ tự tăng dần
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    ll cost = 0;
    // trong khi vẫn chưa nối thành 1 dây
    while (pq.size() > 1)
    {
        // lấy phần tử nhỏ nhất
        int first = pq.top();
        // bỏ nó đi
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost += first + second;
        // first + second: độ dài dây vừa nối
        pq.push(first + second);
    }
    return cost;
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
        for (int &x : a)
            cin >> x;
        cout << cost(a, n) << endl;
    }
}