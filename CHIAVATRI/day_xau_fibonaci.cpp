#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, fb[93];
// ở đây ta hiểu fb[n] là độ dài của dãy xâu G(n); fb(n) = |G(n)|
// vd: n = 6, k = 4;
// A B AB BAB ABBAB BABABBAB
// G(6) = BABABBAB vị trí thứ 4 là A
// Bước 1: sinh dãy fibonaci tới phần tử 93
// Bước 2: nếu n == 1 dãy xâu là A, trả gtri là A
//         nếu n == 2 dãy xâu là B, trả gtri là B
//    vì G(n) = G(n - 2) + G(n - 1)
// => |G(n)| = |G(n - 2)| + |G(n - 1)|
// => nếu k <= fb(n - 2) (tức k <= |G(n)|)
// => ta phải tìm trong G(n - 2)
//   ngược lại , nếu k > fb(n - 2), thì ta tìm trong G(n - 1)
//   tại ví trị k - fb(n - 2);

char find(ll n, ll k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= fb[n - 2])
        return find(n - 2, k);
    return find(n - 1, k - fb[n - 2]);
}
int main()
{
    int t;
    cin >> t;
    fb[1] = 1;
    fb[2] = 1;
    for (int i = 3; i <= 92; i++)
    {
        fb[i] = fb[i - 1] + fb[i - 2];
    }
    while (t--)
    {
        cin >> n >> k;
        cout << find(n, k) << endl;
    }
    return 0;
}