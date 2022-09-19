#include <bits/stdc++.h>
using namespace std;

void solve(int a1[], int a2[], int a3[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    int ok = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            cout << a1[i] << " ";
            ok = 1;
            i++;
            j++;
            k++;
        }
        // x < y
        else if (a1[i] < a2[j])
        {
            i++;
        }
        // x > y và y < z
        // y là nhỏ nhất
        else if (a2[j] < a3[k])
        {
            j++;
        }
        // x > y , y > z
        // z là nhỏ nhất
        else
            k++;
    }
    if (!ok)
        cout << "-1";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int a1[n1], a2[n2], a3[n3];
        for (int &s : a1)
            cin >> s;
        for (int &s : a2)
            cin >> s;
        for (int &s : a3)
            cin >> s;
        solve(a1, a2, a3, n1, n2, n3);
    }
    return 0;
}