#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

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
        bool swapped;
        vector<int> ve;
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
            ve.push_back(i + 1);
            for (int i = 0; i < n; i++)
                ve.push_back(a[i]);
            v.push_back(ve);
            ve.clear();
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << "Buoc " << v[i][0] << ": ";
            for (int j = 1; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        v.clear();
    }
    return 0;
}