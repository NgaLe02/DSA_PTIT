#include <bits/stdc++.h>
using namespace std;

int prime[1000001];
void sieve()
{
    for (int i = 0; i <= 1000001; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= 1000001; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= 1000001; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        int n;
        cin >> n;
        int ok = 0;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] && prime[n - i])
            {
                ok = 1;
                cout << i << " " << n - i << endl;
                break;
            }
        }
        if (!ok)
            cout << "-1\n";
    }
}