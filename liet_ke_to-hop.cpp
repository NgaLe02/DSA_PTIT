#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[16], b[16];
vector<int> ve;

void in()
{
    for (int i = 1; i <= k; i++)
    {
        cout << ve[a[i] - 1] << " ";
    }
    cout << endl;
}
void back_track(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            in();
        }
        else
            back_track(i + 1);
    }
}
int main()
{
    cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int x : s)
    {
        ve.push_back(x);
    }
    n = ve.size();
    back_track(1);
    return 0;
}