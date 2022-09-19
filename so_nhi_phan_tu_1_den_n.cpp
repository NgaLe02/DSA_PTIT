#include <bits/stdc++.h>
using namespace std;

string res[10001]; // lưu các giá trị nhị phân hoặc dùng vector

void solve(int n)
{
    queue<string> q;
    q.push("1");
    int cnt = 1; // đếm xem sinh ra bao nhiêu số nhị phân rồi
    res[1] = "1";
    while (cnt < n)
    {
        // lấy ra phần tử đầu tiên ở hàng đợi
        string top = q.front();
        q.pop();
        res[++cnt] = top + "0";
        res[++cnt] = top + "1";
        q.push(top + "0");
        q.push(top + "1");
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}