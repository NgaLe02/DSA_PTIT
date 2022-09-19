#include <bits/stdc++.h>
using namespace std;
// Tạo 1 mảng b sao chép của mảng a
// Sort mảng b
// Duyệt mảng a, nếu a[i] = b[i] thì a[i] đã ở đúng vị trí
// Ngược lại, duyệt các phần tử phía sau a[i], nếu a[j] = b[i]
// thì swap(a[i], a[j]), và tăng biến cnt.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] == b[i])
                    {
                        cnt++;
                        swap(a[i], a[j]);
                        break;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}