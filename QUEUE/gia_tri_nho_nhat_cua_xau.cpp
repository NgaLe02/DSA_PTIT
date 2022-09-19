#include <bits/stdc++.h>
using namespace std;

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