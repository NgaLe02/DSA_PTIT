#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>;

int n, a[17];
string s;
vector<string> v;

void nhiPhan(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            string tmp = "";
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 1)
                    tmp += s[i - 1];
            }
            v.push_back(tmp);
        }
        else
            nhiPhan(i + 1);
    }
}

void in()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    v.clear();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        nhiPhan(1);
        in();
    }
    return 0;
}