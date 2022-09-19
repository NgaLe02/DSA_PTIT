#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
typedef long long ll;
// Approach: Ma trận [1 1] mũ n sẽ thành [F(n+1) F(n)]
//                   [1 0]               [F(n)   F(n-1)]
//  a^k = a^(k/2) * a^(k/2) * a với k lẻ
//     với ma trận  * a = ma trận nhị phân * a
//      = a^(k/2) * a^(k/2)     với k chẳn

// ma trận a nhân ma trận b, sau đó lưu kết quả vào ma trận a
void nhan(ll a[2][2], ll b[2][2])
{
    ll c[2][2];
    // nhân ma trận
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                c[i][j] %= mod;
            }
        }
    }
    // lưu kết quả vào ma trận a
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = c[i][j];
        }
    }
}
// tinhs a^n
void power(ll a[2][2], ll n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    ll tmp[2][2] = {{1, 1}, {1, 0}};
    power(a, n / 2); // a^(n/2)
    nhan(a, a);      // lúc này a = a^(n/2) , nên có a^(n/2)*a^(n/2)
    // nếu n lẻ ta nhân thêm a
    if (n % 2 == 1)
    {
        nhan(a, tmp);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[2][2] = {{1, 1}, {1, 0}};
        power(a, n);
        cout << a[0][1] << endl;
    }
    return 0;
}