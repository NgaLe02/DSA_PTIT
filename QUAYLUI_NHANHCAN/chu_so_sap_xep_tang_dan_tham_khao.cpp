#include <iostream>
#include <cstring>
using namespace std;
int f[100][10];
int mod = 1e9 + 7;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(f, 0, sizeof(f));
		int n;
		cin >> n;
		for (int i = 0; i <= 9; i++)
		{
			f[1][i] = 1;
		}
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				for (int k = 0; k <= j; k++)
				{
					f[i][j] = (f[i - 1][k] % mod + f[i][j] % mod) % mod;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i <= 9; i++)
		{
			sum = (sum % mod + f[n][i] % mod) % mod;
		}
		cout << sum << endl;
	}
}