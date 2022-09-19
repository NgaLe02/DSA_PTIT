#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(ll n)
{
    queue<string> q;
    q.push("1");
    int cnt = 1; // đếm xem sinh ra bao nhiêu số nhị phân rồi
    while (1)
    {
        //lấy ra phần tử đầu tiên ở hàng đợi
        string top = q.front();
        q.pop();
        if (stoll(top + "0") > n)
        {
            break;
        }
        q.push(top + "0");
        cnt++;
        if (stoll(top + "1") > n)
        {
            break;
        }
        q.push(top + "1");
        cnt++;
    }

    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}