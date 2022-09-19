#include <bits/stdc++.h>
using namespace std;

void change1(string &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '6')
            a[i] = '5';
    }
}

void change2(string &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '5')
            a[i] = '6';
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    int x, y;
    change1(a);
    change1(b);
    x = stoi(a);
    y = stoi(b);
    cout << x + y << " ";
    change2(a);
    change2(b);
    x = stoi(a);
    y = stoi(b);
    cout << x + y << endl;
}