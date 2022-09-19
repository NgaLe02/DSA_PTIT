#include <bits/stdc++.h>
using namespace std;

void in(int a[], int i)
{
    for (int j = 0; j <= i; j++)
        cout << a[j] << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    cout << "Buoc 0: " << a[0] << endl;
    for (int i = 1; i < n; i++)
    {
        cout << "Buoc " << i << ": ";
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        in(a, i);
    }
    return 0;
}