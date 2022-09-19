#include <bits/stdc++.h>
using namespace std;

void generateGray(int n)
{
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    // khi tạo L2 v sẽ gấp đôi phần tử
    int x = (int)pow(2, n);
    for (int i = 2; i < x; i += i)
    // for (int i = 2; i < (1 << n); i = i << 1)
    {
        // tạo L2 bằng cách reverse L1
        for (int j = i - 1; j >= 0; j--)
        {
            v.push_back(v[j]);
        }
        //  thêm 0 vào phía trước L1
        for (int j = 0; j < i; j++)
        {
            v[j] = "0" + v[j];
        }
        // thêm 1 vào phía trước L2
        for (int j = i; j < 2 * i; j++)
        {
            v[j] = "1" + v[j];
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        generateGray(n);
        cout << endl;
    }
    return 0;
}