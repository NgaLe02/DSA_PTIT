#include <bits/stdc++.h>
using namespace std;

int a, b;

int check(int n)
{
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i + n / i;
        }
    }
    if ((int)sqrt(n) * (int)sqrt(n) == n)
        sum -= sqrt(n);
    if (sum > n)
        return 1;
    return 0;
}
int main()
{
    int cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (check(i))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}