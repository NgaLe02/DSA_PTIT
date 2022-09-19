#include <bits/stdc++.h>
using namespace std;
int a[100], X[100], n;
vector<string> res;
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}
void Try(int i, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        if (a[j] > X[i - 1])
        {
            X[i] = a[j];
            if (i > 1)
            {
                string s = "";
                for (int j = 1; j <= i; j++)
                {
                    s += to_string(X[j]) + " ";
                }
                res.push_back(s);
            }
            Try(i + 1, j + 1);
        }
    }
}
int main()
{
    inp();
    X[0] = 0;
    Try(1, 1);
    sort(res.begin(), res.end());
    for (string x : res)
    {
        cout << x << endl;
    }
}
