#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> adj[1001];
bool used[1001];

void dfs(int u)
{
    used[u] = true;
    for (int x : adj[u])
    {
        if (!used[x])
        {
            dfs(x);
        }
    }
}

void inp()
{
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof(used));
        dfs(i);
        for (int j = 1; j <= n; j++)
        {
            if (used[j] == false)
            {
                dem++;
            }
        }
    }
    if(dem != 0) {
    	cout << "NO" << " " << dem << endl; 
	}
	else 
    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        inp();
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}
