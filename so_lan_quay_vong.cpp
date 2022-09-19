#include <bits/stdc++.h>
using namespace std;
// Approach: Số lần quay vòng k bằng chỉ số của sô nhỏ nhất của mảng
// 5   5 1 2 3 4
// min = 1, index = 1
//=> output : 1
// linear search
// O(n)
void solve(int a[], int n)
{
    int min = INT_MAX;
    int ind = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            ind = i;
        }
    }
    cout << ind << endl;
}
// binary search
// số nhỏ nhất là số duy nhất số liền trước nó lớn hơn nó (a[i] < a[j - 1])
// và số sau nó cũng lớn hơn nó
// O(logn)
int solve1(int a[], int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int pre = mid - 1, next = mid + 1;
        if (a[mid] <= a[pre] && a[mid] <= a[next])
        {
            return mid;
        }
        else if (a[mid] <= a[right])
        {
            right = mid - 1;
        }
        else if (a[mid] >= a[left])
            left = mid + 1;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &x : a)
            cin >> x;
        cout << solve1(a, n) << endl;
    }
    return 0;
}