#include <bits/stdc++.h>
using namespace std;

// vd xét xâu aaaaa(5 kí tự) nếu chỉ cần ít nhất 4 kí tự khác a
//  thì thoả mãn ycbt
//  mảng a đếm tần số các chữ số xuất hiện
//  bây h chỉ cần so sánh chữ số có số lần xuất hiện nhiều nhất
//  với tổng số lần xuất hiện của các số còn lại
//  nếu sum + 1 >= cs(max) thì thoả mãn
int check(string s)
{
    int a[26];
    for (int i = 0; i < 26; i++)
        a[i] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a']++;
    }
    sort(a, a + 26);
    int sum = 0;
    for (int i = 0; i < 25; i++)
        sum += a[i];
    if (sum + 1 >= a[25])
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (check(s))
            cout << "1\n";
        else
            cout << "-1\n";
    }
    return 0;
}