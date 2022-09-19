#include <bits/stdc++.h>
using namespace std;

// a: số chứ số 4
// b: số chữ số 7
// 4a + 7b = n;
// tìm số nhỏ nhất nên kết quả có dạng: 77..., 44...77, 4444...
// nếu n chia hết cho 4, kết quả có dạng 4...4(s số 4: 4s = n)
// nếu n chia hết cho 7, kết quả có dạng 7...7(s số 7: 7s = n)
// nếu ko chia hết cho 4, 7 ta trừ đi 4 hoặc 7 để nó chia hết cho 4 hoặc 7
void solve(int n)
{
    int a = 0, b = 0;
    while (n > 0)
    {
        if (n % 7 == 0)
        {
            b++;
            n -= 7;
        }
        else if (n % 4 == 0)
        {
            a++;
            n -= 4;
        }
        else
        {
            a++;
            n -= 4;
        }
    }
    if (n < 0)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < a; i++)
    {
        cout << 4;
    }
    for (int i = 0; i < b; i++)
    {
        cout << 7;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}