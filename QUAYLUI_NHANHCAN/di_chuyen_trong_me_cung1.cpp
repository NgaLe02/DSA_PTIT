#include <bits/stdc++.h>
using namespace std;

int n, ok;
int a[11][11];
string s;
void solve(int i, int j)
{
    // khi đã di chuển tới ô a[n-1][n-1]
    if (i == n - 1 && j == n - 1)
    {
        cout << s << " ";
        ok = 1;
        return;
    }
    // nếu ô phía dưới ô hiện tai a[i][j] là 1 thì ta di chuyển
    // xuống  ô  đó a[i + 1][j]
    if (a[i + 1][j] == 1)
    {
        s += 'D';
        solve(i + 1, j);
        // sau khi thực hiện xong solve(i + 1, j) nó sẽ
        //  backtrack , thực hiện lệnh 25, xoá đi bước đi ở s[] này
        //  để đi theo cách khác từ a[i][j] nếu có
        s.erase(s.length() - 1);
    }
    // nếu ô bên phải ô hiện tai a[i][j] là 1 thì ta di chuyển
    // xuống  ô  đó a[i][j + 1]
    if (a[i][j + 1] == 1)
    {
        s += 'R';
        solve(i, j + 1);
        s.erase(s.length() - 1);
    }
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
                cout << "-1";
            cout << endl;
        }
    }
}
