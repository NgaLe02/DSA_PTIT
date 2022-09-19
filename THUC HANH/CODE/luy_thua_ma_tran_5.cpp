#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;
typedef long long ll;
typedef vector<vector<ll>> vll;
//  a^k = a^(k/2) * a^(k/2) * a với k lẻ
//     với ma trận  * a = ma trận nhị phân * a
//      = a^(k/2) * a^(k/2)     với k chẳn

// ma trận a nhân ma trận b, sau đó lưu kết quả vào ma trận a
void nhan(vll &a, vll &b, int n)
{
    ll c[n][n];
    // nhân ma trận
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                c[i][j] %= mod;
            }
        }
    }
    // lưu kết quả vào ma trận a
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = c[i][j];
        }
    }
}

// tính a^k với ma trận a có n dòng, n cột
void pow(vll &a, int n, int k)
{
    vll tmp(n);
    // tạo ma trận đơn vị
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // i == j, nằm trên đường chéo chính
            if (i == j)
                tmp[i].push_back(1);
            else
                tmp[i].push_back(0);
        }
    }
    // tính xong a^k
    while (k)
    {
        if (k % 2 == 1)
        {
            nhan(tmp, a, n);
        }
        nhan(a, a, n);
        k /= 2;
    }
    // in
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += (tmp[n - 1][i] % mod);
        tong %= mod;
    }
    cout << tong << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        pow(a, n, k);
    }
    return 0;
}
