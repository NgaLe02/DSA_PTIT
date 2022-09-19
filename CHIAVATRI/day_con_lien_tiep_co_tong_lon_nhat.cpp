#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t ; cin >> t;
	while(t--)
	{
		int n ; cin >> n;
		int a[n]; for(int &x : a) cin >> x;
		int sum = 0 , ans = 0;
		for(int i = 0 ; i < n ;i++)
		{
			sum += a[i];
			ans = max(ans , sum);
			sum = max(sum , 0);
		}
		cout << ans << endl;
	}
}
