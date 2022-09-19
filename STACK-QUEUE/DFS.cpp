#include <bits/stdc++.h>
using namespace std;
/*
10
0 1 0 0 1 0 0 1 0 1
1 0 1 1 0 1 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 1 0 1 0 0
1 0 0 0 0 1 1 0 1 1
0 1 0 1 1 0 1 0 0 1
0 0 0 0 1 1 0 1 1 1
1 0 0 1 0 0 1 0 1 0
0 0 0 0 1 0 1 1 0 1
1 0 0 0 1 1 1 0 1 0
3 9
*/
vector<int> adj[11];
int a[11][11];
int visited[11];
int parent[11];
int n, u, v;
void inp()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> u >> v;
	cout << "Tim duong di tu dinh " << u << " den dinh " << v << " cua G su dung DFS: ";
	cout << "u = " << u << ", v = " << v << endl;
	cout << "DFS(" << u << ") = {";
	memset(visited, 0, sizeof(visited));
}

void chuyenDoiMaTranKe_DanhSachKe()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i][j] == 1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << " : ";
	// 	for (int j = 0; j < adj[i].size(); j++)
	// 	{
	// 		cout << adj[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}

void DFS(int u, int x)
{
	cout << u << "(" << x << "), ";
	visited[u] = 1;
	x = u;
	for (int t : adj[u])
	{
		if (!visited[t])
		{
			parent[t] = x;
			DFS(t, x);
		}
	}
}
void oupPath()
{
	memset(parent, 0, sizeof(parent));
	DFS(u, 0);
	cout << "}\n";
	cout << "Ket luan: Duong di tu dinh " << u << "den dinh " << v << "la: ";
	if (!visited[v])
	{
		cout << "-1" << endl;
	}
	else
	{
		vector<int> path;
		// tim duong di
		//  bat dau tu dinh t
		while (u != v)
		{
			path.push_back(v);
			// lat nguoc lai
			v = parent[v];
		}
		path.push_back(u);
		// reverse(path.begin(), path.end());
		for (int x : path)
		{
			cout << x << " <- ";
		}
	}
}
int main()
{
	inp();
	chuyenDoiMaTranKe_DanhSachKe();
	oupPath();
}
