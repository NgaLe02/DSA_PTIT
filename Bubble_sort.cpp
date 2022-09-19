#include <bits/stdc++.h>
using namespace std;

void in(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        // với n = 4: i = 0, j chạy tử  0 tới 3
        // i = 1, j chạy từ  0 tới 2
        // khi dùng bubble sort, ta sẽ đẩy dần số lớn nhất ra cuổi mảng
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        // nếu swap(a[i], a[j]) tức mảng chưa dk sort
        // ngưược lại mảng đã được sort, dừng bubble sort
        if (!swapped)
            break;
        cout << "Buoc " << i + 1 << ": ";
        in(a, n);
    }
    return 0;
}