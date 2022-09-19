#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

void sapxep4(int a[], int n)
{
    vector<int> res[n];
    for (int i = 0; i < n - 1; i++)
    {
        int ok = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ok = 1;
            }
        }
        if (ok == 1)
        {
            for (int j = 0; j < n; j++)
            {
                res[i].push_back(a[j]);
            }
        }
        else
            break;
    }
    for (int i = res[i].size(); i >= 0; i--)
    {
        cout << "Buoc " << i + 1 << ": ";
        for (int x : res[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &x : a)
            cin >> x;
        sapxep4(a, n);
    }
    return 0;
}