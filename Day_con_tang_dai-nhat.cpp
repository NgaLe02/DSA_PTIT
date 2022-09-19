#include <bits/stdc++.h>
using namespace std;

/* Input  : arr[] = {3, 10, 2, 11}
b[] = {1, 1, 1, 1} (initially)
Iteration-wise simulation :

arr[2] > arr[1] {b[2] = max(b[2], b[1]+1)=2}
arr[3] < arr[1] {No change}
arr[3] < arr[2] {No change}
arr[4] > arr[1] {b[4] = max(b [4], b[1]+1)=2}
arr[4] > arr[2] {b[4] = max(b [4], b[2]+1)=3}
arr[4] > arr[3] {b[4] = max(b [4], b[3]+1)=3} */
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    // b[n] la mang danh dau do dai day tang tai vi tri b[i] bat ky
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            //
            if (a[i] > a[j] && b[i] < b[j] + 1)
            {
                b[i] = b[j] + 1;
            }
        }
    }
    int best = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > best)
            best = b[i];
    }
    cout << best << endl;
}