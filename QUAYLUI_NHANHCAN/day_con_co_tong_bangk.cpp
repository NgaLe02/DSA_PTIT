#include <bits/stdc++.h>
using namespace std;

int n, k, size;
int a[100], b[100];
int ok, ok1 = 1;

// dùng sinh xâu nhị phân
// a[i] = 1 thì tính tổng sum tại b[i]
// nếu sum == k thì cập nhật;
int check()
{
    int s = 0, dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            s += b[i];
            dem++;
        }
    }
    if (s == k)
        return dem;
    return -1;
}

void capnhap()
{
    if (check() > 0)
    {
        ok1 = 0;
        size = check();
        int cnt = 0;
        cout << "[";
        for (int i = 1; i <= n; i++)
            if (a[i] == 1)
            {
                cnt++;
                cout << b[i];
                if (cnt != size)
                    cout << " ";
                else
                    cout << "]";
            }
        cout << " ";
    }
}
void backtrack(int i)
{
    for (int j = 1; j >= 0; j--)
    {
        a[i] = j;
        if (i == n)
        {
            capnhap();
        }
        else
            backtrack(i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ok = 1, ok1 = 1;
        b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b, b + n + 1);
        backtrack(1);
        if (ok1)
        {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}