#include <bits/stdc++.h>
using namespace std;

// Bước 1: Vì các giá trị đối xứng qua giá trị n nên
// ta xét các giá trị bên nửa trái
// tính: len = 2^n / 2
// Bước 2: nếu n == 1 in 1;
// nếu len == k, k nằm giữa dãy nên in n;
// nếu k > len ta lại lấy đối xứng qua vị trí có giá trị n
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        long long len = pow(2, n) / 2;
        while (1)
        {
            if (n == 1)
            {
                cout << 1;
                break;
            }
            if (len == k)
            {
                cout << n;
                break;
            }
            if (k > len)
            {
                k = len - (k - len);
            }
            n--;
            len /= 2;
        }
        cout << endl;
    }
}