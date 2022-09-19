#include <bits/stdc++.h>
using namespace std;
// tự làm
// mảng a đếm tần suất của các chữ cái
// cho vào hàng đợi ưu tiên( sẽ lấy phần tử lớn nhất ra)
// để có gtri xâu nhỏ nhất,
// n lần loại bỏ, mỗi lần loại bỏ ta sẽ bỏ đi 1 lần xuất hiện
// của kí tự xuất hiện nhiều nhất tại thời điểm đó
// ví dụ: 1 4 5 n = 3;
// b1: 1 4 4 n = 2;
// b2: 1 4 3 n = 1;
// b3: 1 3 3 n = 0;
// ta ko thực hiện 5 - 3 luôn nhé!, nếu thực hiện z ta có 1 4 2 = 21 > 1 3 3 = 19
long long solve(string s, int n)
{
    int a[26];
    for (int i = 0; i < 26; i++)
        a[i] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'A']++;
    }
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] > 0)
            pq.push(a[i]);
    }
    // cout << pq.size() << endl;
    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    while (n--)
    {
        int top = pq.top();
        pq.pop();
        top--;
        pq.push(top);
    }
    long long sum = 0;
    while (!pq.empty())
    {
        int top = pq.top();
        sum += (long long)top * top;
        pq.pop();
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, n) << endl;
    }
    return 0;
}