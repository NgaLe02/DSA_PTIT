#include <bits/stdc++.h>
using namespace std;

int solve(int s)
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
        if (top.first == 1)
            return top.second;
        int x = top.first;
        // chạy i từ 2
        // ko nên chạy từ 1 làm mất time vì max(1, s) là s
        // như vậy ở bước này ta ko thay đổi được s
        // vì vậy ta nên duyệt i từ 2
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                int m = max(i, x / i);
                if (se.find(m) == se.end())
                {
                    q.push({m, top.second + 1});
                    se.insert(m);
                }
            }
        }
        if (se.find(x - 1) == se.end())
        {
            q.push({x - 1, top.second + 1});
            se.insert(x - 1);
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}