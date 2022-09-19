#include <bits/stdc++.h>
using namespace std;

int n, m;
int degree_in[1001];
int degree_out[1001];

// đồ thị có hướng liên thông có chu trình euler nếu:
// các đỉnh có bán bậc ra bằng bán bậc vào

void inp()
{
    memset(degree_in, 0, sizeof(degree_in));
    memset(degree_out, 0, sizeof(degree_out));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        degree_out[x]++;
        degree_in[y]++;
    }
}

int check()
{
    for (int i = 1; i <= n; i++)
    {
        if (degree_in[i] != degree_out[i])
            return 0;
    }
    return 1;
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