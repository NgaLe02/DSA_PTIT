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
        ktao();
        ok = 1;
        while (ok == 1)
        {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << " ";
            sinh();
        }
        cout << endl;
    }
}