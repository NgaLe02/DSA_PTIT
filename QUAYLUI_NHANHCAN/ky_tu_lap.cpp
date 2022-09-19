#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
#define pi pair<int, int>;

// Approach:
// Bước 1: Vì có N<10 xâu nên ta đi tính số lần lặp
// giữa hai cặp xâu bất kỳ lưu trong ma trận kề.
// Giờ thì bài toán trở thành có một đồ thị vô hướng N đỉnh
// khoảng cách giữa các đỉnh là
// số lần lặp giữa hai cặp xâu tương ứng.
// Bước 2: Ta dùng thuật toán quay lui sinh tất cả các hoán vị,
// mỗi hoán vị ta đi tính tổng độ dài đường đi và tìm min.
// Để ý rằng các khoảng cách là không âm
// nên ta dùng kỹ thuật nhánh cận nhánh nào mà
// độ dài lớn hơn min thì ta lui luôn không đi tiếp
// Note:
// Do N<10 mà mỗi độ chênh lệch cùng lắm là 26 nên khởi gán min=300

int n, FOPT = 999;
int a[11][11];
int x[11];
bool unused[11];
vector<string> v;

// tính số lần lặp lại các kí tự giữa 2 xâu a và b
int numberRepeat(string a, string b)
{
    int dem = 0;
    for (int i = 0; i < a.size(); i++)
    {
        bool ok = false;
        for (int j = 0; j < b.size(); j++)
        {
            if (b[j] == a[i])
            {
                ok = true;
                break;
            }
        }
        if (ok)
            dem++;
    }
    return dem;
}

// tính số lần lặp lại
int calc()
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // số lần lặp lại của xâu x[i] và x[i+1]
        sum += a[x[i]][x[i + 1]];
    }
    return sum;
}

void hoanVi(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (unused[j])
        {
            x[i] = j;
            unused[j] = false;
            if (i == n - 1)
            {
                int temp = calc();
                if (temp < FOPT)
                {
                    FOPT = temp;
                }
            }
            else
                hoanVi(i + 1);
            unused[j] = true;
        }
    }
}

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // chuyển sang ma trận kề
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // số lần lặp lại của xâu thứ i và thứ j
            a[i][j] = numberRepeat(v[i], v[j]);
            a[j][i] = numberRepeat(v[i], v[j]);
        }
    }
    memset(unused, true, sizeof(unused));
    hoanVi(0);
    cout << FOPT << endl;
    return 0;
}