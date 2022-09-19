#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
int a[100];
int ok;

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
int check()
{
    int dem = 0, size = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            ++size;
        else
        {
            if (size > k)
                return 0;
            else if (size == k)
                ++dem;
            size = 0;
        }
    }
    if (a[n] == 0)
    {
        if (size > k)
            return 0;
        else if (size == k)
            ++dem;
    }
    return dem == 1;
}
int main()
{
    vector<string> v;
    cin >> n >> k;
    ok = 1;
    ktao();
    while (ok)
    {
        if (check())
        {
            ++ans;
            string t = "";
            for (int i = 1; i <= n; i++)
            {
                if (a[i])
                    t += "B";
                else
                    t += "A";
            }
            v.push_back(t);
        }
        sinh();
    }
    cout << ans << endl;
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}