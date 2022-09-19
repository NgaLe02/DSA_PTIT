#include <bits/stdc++.h>
using namespace std;
// xem so_ugly.cpp

int Ugly(int n)
{
    int ugly[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int mul2 = 2, mul3 = 3, mul5 = 5;
    int nextUgly = 1;
    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        nextUgly = min(mul2, mul3, mul5);
        ugly[i] = nextUgly;
        if (nextUgly == mul2)
        {
            i2++;
            mul2 = ugly[i2] * 2;
        }
        if (nextUgly == mul3)
        {
            i3++;
            mul3 = ugly[i3] * 3;
        }
        if (nextUgly == mul5)
        {
            i5++;
            mul5 = ugly[i5] * 5;
        }
    }
    return nextUgly;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << Ugly(n) << endl;
    }
    return 0;
}
