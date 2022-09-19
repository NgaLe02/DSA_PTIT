#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

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
        for (int i = 0; i < n - 1; i++)
        {
            vector<int> ve;
            ve.push_back(i + 1);
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                }
            }

            for (int i = 0; i < n; i++)
                ve.push_back(a[i]);
            v.push_back(ve);
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++)
        {
            cout << "Buoc " << v[i][0] << ": ";
            for (int j = 1; j < n + 1; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        v.clear();
    }
    return 0;
}