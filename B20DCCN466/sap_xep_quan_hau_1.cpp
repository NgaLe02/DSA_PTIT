#include <bits/stdc++.h>
using namespace std;

int n;
int cot[11], xuoi[101], nguoc[101];
int cnt = 0;
void back_track(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1])
        {
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            if (i == n)
                cnt++;
            else
                back_track(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(cot, 1, sizeof(cot));
        memset(nguoc, 1, sizeof(nguoc));
        memset(xuoi, 1, sizeof(xuoi));
        cnt = 0;
        back_track(1);
        cout << cnt << endl;
    }
    return 0;
}