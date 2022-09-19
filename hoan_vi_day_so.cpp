#include <bits/stdc++.h>
using namespace std;

int n;
int a[10], b[10];
bool unused[11];

void in()
{
    for (int i = 1; i <= n; i++)
    {
        cout << b[a[i]] << " ";
    }
    cout << endl;
}
void back_track(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (unused[j] == true)
        {
            a[i] = j;
            unused[j] = false;
            if (i == n)
            {
                in();
            }
            else
                back_track(i + 1);
            unused[j] = true;
        }
    }
}
int main()
{
    cin >> n;
    b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    memset(unused, true, sizeof(unused));
    back_track(1);
    return 0;
}