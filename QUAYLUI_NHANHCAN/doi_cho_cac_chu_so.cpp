#include <bits/stdc++.h>
using namespace std;

void ql(string s, int k)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (k == 0)
            break;
        int tmp = -1;
        int pos; // vị trí pt lớn nhất bên phải s[i]
        // tìm phần tử bên phải của s[i] lớn nhất là tmp
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] >= tmp)
            {
                tmp = s[j];
                pos = j;
            }
        }
        // nếu pt lớn nhất đó lớn hơn s[i] thì đổi chỗ
        if (tmp > s[i])
        {
            swap(s[i], s[pos]);
            --k;
        }
    }
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int k;
        cin >> k >> s;
        ql(s, k);
    }
}