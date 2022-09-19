#include <bits/stdc++.h>
using namespace std;

// xem thêm bài : di chuyển trong mê cung 1
int n, ok;
int a[11][11], visited[11][11];
int dem = 0;      // đếm số cách có thể đi
vector<string> v; // lưu các bước đi
// visited : 0 : chưa thăm
//           1 : đã thăm
string s;
void solve(int i, int j)
{
    // khi đã di chuển tới ô a[n-1][n-1]
    if (i == n - 1 && j == n - 1)
    {
        v.push_back(s);
        ok = 1;
        return;
    }
    visited[i][j] = 1;
    // gán để tránh việc backtrack lại mãi tại a[i][j]
    if (i < n - 1 && a[i + 1][j] == 1 && visited[i + 1][j] == 0)
    {
        s += 'D';
        solve(i + 1, j);
        s.erase(s.length() - 1);
    }

    if (j >= 0 && a[i][j - 1] == 1 && visited[i][j - 1] == 0)
    {
        s += 'L';
        solve(i, j - 1);
        s.erase(s.length() - 1);
    }

    if (j < n - 1 && a[i][j + 1] == 1 && visited[i][j + 1] == 0)
    {
        s += 'R';
        solve(i, j + 1);
        s.erase(s.length() - 1);
    }

    if (i >= 0 && a[i - 1][j] == 1 && visited[i - 1][j] == 0)
    {
        s += 'U';
        solve(i - 1, j);
        s.erase(s.length() - 1);
    }
    // lúc này a[i][j] chưa dk thăm để có thể tìm đường đi mới
    visited[i][j] = 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s = "";
        ok = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        // nếu a[0][0] = 0 thì ko có đường đi
        if (a[0][0] == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            solve(0, 0);
            if (ok == 0)
            {
                cout << "-1";
                cout << endl;
            }
            else
            {
                cout << v.size() << " ";
                for (string x : v)
                {
                    cout << x << " ";
                }
                cout << endl;
                v.clear();
            }
        }
    }
}
