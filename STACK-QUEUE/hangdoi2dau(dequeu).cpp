#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

void solve(string s)
{
    if (s == "PRINTFRONT")
    {
        if (dq.empty())
            cout << "NONE\n";
        else
            cout << dq.front() << endl;
    }
    else if (s == "PRINTBACK")
    {
        if (dq.empty())
            cout << "NONE\n";
        else
            cout << dq.back() << endl;
    }
    else if (s == "POPFRONT")
    {
        if (!dq.empty())
            dq.pop_front();
    }
    else if (s == "POPBACK")
    {
        if (!dq.empty())
            dq.pop_back();
    }
    else
    {
        stringstream ss(s);
        string t2, t1;
        int cnt = 0;
        while (ss >> t2)
        {
            if (cnt == 0)
                t1 = t2;
            cnt++;
        }
        int m = (int)stoll(t2);
        if (t1 == "PUSHFRONT")
            dq.push_front(m);
        else
            dq.push_back(m);
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        solve(s);
    }
    return 0;
}