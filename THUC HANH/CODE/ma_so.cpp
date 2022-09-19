#include <bits/stdc++.h>
using namespace std;

int n;
char a[6];
bool unused[6];
vector<string> start;
vector<string> kt;
vector<string> kqua;
int b[6];

void hoanViStart(int i)
{
    for (char j = 'A'; j < (char)('A' + n); j++)
    {
        if (unused[j - 65] == true)
        {
            a[i] = j;
            unused[j - 65] = false;
            if (i == n - 1)
            {
                string tmp = "";
                for (int i = 0; i < n; i++)
                    tmp += a[i];
                start.push_back(tmp);
            }
            else
                hoanViStart(i + 1);
            unused[j - 65] = true;
        }
    }
}

void hoanViEnd(int i)
{
    for (int j = 1; j <= n; j++)
    {
        b[i] = j;
        if (i == n - 1)
        {
            string tmp = "";
            for (int i = 0; i < n; i++)
                tmp += (to_string)(b[i] + '0' - 48);
            kt.push_back(tmp);
        }
        else
            hoanViEnd(i + 1);
    }
}
int main()
{
    cin >> n;
    memset(unused, true, sizeof(unused));
    hoanViStart(0);
    hoanViEnd(0);
    for (string x : start)
    {
        for (string y : kt)
        {
            kqua.push_back(x + y);
        }
    }
    for (string x : kqua)
    {
        cout << x << endl;
    }
    return 0;
}