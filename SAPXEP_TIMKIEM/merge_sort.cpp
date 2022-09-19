#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1; // số phần tử đoạn bên trái
    int m1 = r - m;     // số phần tử đoạn bên phải
    int x[n1], y[m1];
    // 2 mảng tạm để lưu đoạn bên trái và đoạn bên phải
    // copy các phần tử chỉ số l cho tới chỉ số m vào mảng x
    for (int i = 0; i < n1; i++)
        x[i] = a[l + i];
    // copy các phần tử từ chỉ số m + 1 tới r vào mảng y
    for (int i = 0; i < m1; i++)
        y[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < m1)
    {
        if (x[i] <= y[j])
        {
            a[k] = x[i];
            k++;
            i++;
        }
        else
        {
            a[k] = y[j];
            k++;
            j++;
        }
    }
    // nếu còn phần tử ở mảng x chưa vào mảng a
    while (i < n1)
    {
        a[k++] = x[i];
        i++;
    }
    // nếu còn phần tử ở mảng y chưa vào mảng a
    while (j < m1)
    {
        a[k++] = y[j];
        j++;
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l >= r)
        return; // điều kiện dừng thao tác chia
    int m = (l + r) / 2;
    merge_sort(a, l, m);     // gọi đệ quy dãy bên trái
    merge_sort(a, m + 1, r); // gọi đệ quy dãy bên phải
    merge(a, l, m, r);
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        merge_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}