#include <bits/stdc++.h>
using namespace std;

int knapStack(int size[], int val[], int n, int m)
{
	// cost[i]: giá trị tối đa mà có thể thực hiện được với
	// một cái túi có sức chứa i
	int cost[m + 1];
	memset(cost, 0, sizeof(cost));
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j >= 0; j--)
		{
			if (j - size[i] >= 0)
			{
				if (cost[j] < (cost[j - size[i]] + val[i]))
				{
					cost[j] = cost[j - size[i]] + val[i];
				}
			}
		}
	}
	return cost[m];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		// n loại mặt hàng, trọng lượng tối đa m
		int n, m;
		cin >> n >> m;
		int size[n];
		int val[n];
		for (int &x : size)
			cin >> x;
		for (int &x : val)
			cin >> x;
		cout << knapStack(size, val, n, m) << endl;
	}
	return 0;
}