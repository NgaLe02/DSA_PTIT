#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k)
{
    k++;
    int dp[n];
    map<int, int> ma;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dp[i] = s.length();
    }
    for (int i = 0; i < k; i++)
    {
        ma[dp[i]]++;
    }
    int dem = 0;
    for (auto x : ma)
    {
        dem += (x.second - 1) * x.second / 2;
    }
    for (int i = k; i < n; i++)
    {
        int j = i - k;
        ma.at(dp[j])--;
        ma[dp[i]]++;
        dem += ma[dp[i]] - 1;
    }
    cout << dem << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    solve(n, k);
}