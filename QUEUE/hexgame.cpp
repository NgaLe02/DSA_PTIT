#include <bits/stdc++.h>
using namespace std;
// ý tưởng như bài : Quay hình vuông
string s, e = "1238004765";
set<string> se;
queue<pair<string, int>> q;
pair<string, int> top;
void inp()
{
    s = "";
    int n;
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        s += (n + '0');
    }
    //  cout << s << endl;
}
int BFS(string s)
{
    q.push({s, 0});
    se.insert(s);
    while (!q.empty())
    {
        top = q.front();
        q.pop();
        string x = top.first;
        if (x == e)
            return top.second;
        // string tmp = "";
        // tmp = tmp + x[3] + x[0] + x[2] + x[7] + x[4] + x[1] + x[6] + x[8] + x[5] + x[9];
        swap(x[0], x[3]);
        swap(x[3], x[1]);
        swap(x[3], x[5]);
        swap(x[3], x[8]);
        swap(x[3], x[7]);
        if (se.find(x) == se.end())
        {
            q.push({x, top.second + 1});
            se.insert(x);
        }
        x = top.first;
        swap(x[1], x[4]);
        swap(x[4], x[2]);
        swap(x[4], x[6]);
        swap(x[4], x[9]);
        swap(x[4], x[8]);
        // tmp = "";
        // tmp = tmp + x[0] + x[4] + x[1] + x[3] + x[8] + x[5] + x[2] + x[7] + x[9] + x[6];
        if (se.find(x) == se.end())
        {
            q.push({x, top.second + 1});
            se.insert(x);
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
        se.clear();
        while (!q.empty())
        {
            q.pop();
        }
        inp();
        cout << BFS(s) << endl;
    }
    return 0;
}