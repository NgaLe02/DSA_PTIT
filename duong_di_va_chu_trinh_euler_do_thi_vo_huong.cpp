#include <bits/stdc++.h>
using namespace std;

int n, m;
int degree[1001];
// Đồ thị vô hướng liên thông:
// có chu trình euler nếu: bậc của các đỉnh đều là chẵn
//=> bậc các đỉnh khi chia dư cho 2 đều bằng 0, nên cnt = 0
// có đường đi euler nếu: có 2 đỉnh có bậc lẻ
// bậc các đỉnh khi chia dư cho 2, có 2 đỉnh chia dư bằng 1, nên cnt = 2

void inp()
{
    memset(degree, 0, sizeof(degree));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        // đếm bậc
        degree[x]++;
        degree[y]++;
    }
}

int check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += degree[i] % 2;
    }
    if (cnt == 0)
        return 2;
    else if (cnt == 2)
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        cout << check() << endl;
    }
    return 0;
}