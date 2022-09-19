#include <bits/stdc++.h>
using namespace std;

// Approach: Ma trận [0 1 0] mũ n sẽ thành [a  F(n-2) d]
//                   [0 0 1]               [b  F(n-1) e]
//                   [1 1 1]               [c  F(n)   f]
// F(n) = T(1) + T(2) + ... + T(n)
// F(n) = (T(n) + T(n+2)) / 2 - 1
//  a^k = a^(k/2) * a^(k/2) * a với k lẻ
//     với ma trận  * a = ma trận nhị phân * a
//      = a^(k/2) * a^(k/2)     với k chẳn
const long long mod = 1e15 + 7;
typedef long long ll;

void nhan(ll a[3][3], ll b[3][3])
{
    ll c[3][3];
    // nhân ma trận
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                c[i][j] %= mod;
            }
        }
    }
    // lưu kết quả vào ma trận a
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = c[i][j];
        }
    }
}
// tinhs a^n
void power(ll a[3][3], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll tmp[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
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
    while (t > 0)
    {
        ll n;
        cin >> n;
        ll a[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
        ll ans = 0;
        power(a, n + 2);
        // cout << a[0][1] << " " << a[2][1] << endl;
        ans = (ll)(a[0][1] + a[2][1]) / 2 - 1;
        cout << ans % mod << endl;
        t--;
    }
    return 0;
}