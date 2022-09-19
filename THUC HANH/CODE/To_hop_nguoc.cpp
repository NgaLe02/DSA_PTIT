#include <bits/stdc++.h>
using namespace std;
int n, k, ok, a[100];
void kt()
{
    for (int i = 1; i <= k; i++)
        a[i] = i;
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        vector<string> v;
        kt();
        ok = 1;
        while (ok)
        {
            string tmp = "";
            for (int i = 1; i <= k; i++)
            {
                tmp += to_string(a[i]) + " ";
            }
            v.push_back(tmp);
            sinh();
        }
        reverse(v.begin(), v.end());
        for (string x : v)
        {
            cout << x << endl;
        }
    }
    return 0;
}
