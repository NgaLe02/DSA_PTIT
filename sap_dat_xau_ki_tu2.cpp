#include <bits/stdc++.h>
using namespace std;

// 1 phần tử, nếu vị trí đầu tiên là 1,
// vị trí tiếp theo sẽ là (n + 1), (2n + 1), (3n + 1),...
// ví dụ 1 phần tử lặp lại nhiều nhất trong xâu 4 lần :
// vị trí sẽ là : 1, n + 1, 2n + 1, 3n + 1
// => 3n + 1 <= s.size()
//(4 - 1) * n +1 <= s.size()
// (a[25] - 1) * n + 1
int check(string s, int n)
{
    int a[26];
    for (int i = 0; i < 26; i++)
        a[i] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'A']++;
    }
    sort(a, a + 26);
    if ((a[25] - 1) * n + 1 <= s.length())
        return 1;
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
        string s;
        cin >> s;
        if (check(s, n))
            cout << "1\n";
        else
            cout << "-1\n";
    }
    return 0;
}