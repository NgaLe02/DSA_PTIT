#include <bits/stdc++.h>
using namespace std;

int k, m, n;
vector<string> dic;
vector<string> kqua;
string s = "";
char a[1001][1001];
int vs[1001][1001];

void inp()
{
    cin >> k >> n >> m;
    dic.resize(k);
    for (int i = 0; i < k; i++)
        cin >> dic[i];
    a[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            vs[i][j] = 0;
        }
    }
    s = "";
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void ql(int i, int j)
{
    s += a[i][j];
    vs[i][j] = 1;
    cout << s << endl;
    for (int j = 0; j < dic.size(); j++)
    {
        if (s == dic[j])
        {
            kqua.push_back(s);
        }
    }
    for (int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && vs[i][j] == 0)
        {
            ql(i1, j1);
        }
    }
    vs[i][j] = 0;
    s.pop_back();
}

void outp()
{
    if (kqua.size() == 0)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < kqua.size(); i++)
        {
            cout << kqua[i] << " ";
        }
        cout << endl;
    }
    kqua.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        ql(0, 0);
        outp();
    }
}
