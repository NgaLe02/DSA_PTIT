#include <bits/stdc++.h>
using namespace std;
int n, ok;
int a[1001];

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}
void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
    }
    else
    {
        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        vector<string> v;
        ktao();
        ok = 1;
        while (ok)
        {
            string tmp = "";
            for (int i = 1; i <= n; i++)
                tmp += to_string(a[i]);
            v.push_back(tmp);
            sinh();
        }
        reverse(v.begin(), v.end());
        for (string x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}