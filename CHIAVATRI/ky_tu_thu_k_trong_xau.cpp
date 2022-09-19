#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long len = pow(2, n) / 2;
        while (true)
        {
            if (n == 1)
            {
                cout << 'A' << endl;
                break;
            }
            if (len == k)
            {
                cout << char(n - 1 + 'A') << endl;
                break;
            }
            if (k > len)
            {
                k = len - (k - len);
            }
            n--;
            len /= 2;
        }
    }
}