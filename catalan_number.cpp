#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Catalan(int n)
{
    ll C[n];
    C[0] = 1;
    C[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        C[i] = 0;
        for (int j = 0; j < i; j++)
        {
            C[i] += C[j] * C[i - j - 1];
        }
    }
    return C[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << Catalan(n) << endl;
    }
    return 0;
}