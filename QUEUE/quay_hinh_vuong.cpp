#include <bits/stdc++.h>
using namespace std;

string s, e;

void inp()
{
	s = "";
	e = "";
	int n, m = 6;
	while (m--)
	{
		cin >> n;
		s += (n + '0');
	}
	m = 6;
	while (m--)
	{
		cin >> n;
		e += (n + '0');
	}
}
int BFS(string s)
{
	set<string> se;
	queue<pair<string, int>> q;
	q.push({s, 0});
	se.insert(s);
	while (!q.empty())
	{
		pair<string, int> top = q.front();
		q.pop();
		string x = top.first;
		if (x == e)
			return top.second;
		string tmp = "";
		tmp = tmp + x[3] + x[0] + x[2] + x[4] + x[1] + x[5];
		if (se.find(tmp) == se.end())
		{
			q.push({tmp, top.second + 1});
			se.insert(tmp);
		}
		tmp = "";
		tmp = tmp + x[0] + x[4] + x[1] + x[3] + x[5] + x[2];
		if (se.find(tmp) == se.end())
		{
			q.push({tmp, top.second + 1});
			se.insert(tmp);
		}
	}
	return 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		inp();
		cout << BFS(s) << endl;
	}
	return 0;
}