#include <bits/stdc++.h>
using namespace std;

int solve(int s, int t)
{
    queue<pair<int, int>> q;
    // lưu số hiện tại và lưu số bước để chuyển đổi
    //  từ S sang số hiện tại
    set<int> se;
    // lưu các số đã được duyệt tránh việc số được duyệt lại
    se.insert(s);
    q.push({s, 0});
    // s: số bắt đầu
    // 0: số bước thực hiện
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == t)
            return top.second;
        if (top.first * 2 == t || top.first - 1 == t)
            return top.second + 1;
        // nếu số hiện tại chưa xuất hiện lần nào thì thực hiện: -1 nếu >t
        //                     *2 nếu <t
        //                     -1 nếu >t
        if (se.find(top.first * 2) == se.end() && top.first < t)
        {
            q.push({top.first * 2, top.second + 1});
            se.insert(top.first * 2);
        }
        if (se.find(top.first - 1) == se.end() && top.first > 1)
        {
            q.push({top.first - 1, top.second + 1});
            se.insert(top.first - 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
    return 0;
}