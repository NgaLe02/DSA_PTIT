#include <bits/stdc++.h>
using namespace std;
void in(char a, char b)
{
    cout << a << " -> " << b << endl;
}
void thapHaNoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    thapHaNoi(n - 1, a, c, b);
    in(a, c);
    thapHaNoi(n - 1, b, a, c);
}
int main()
{
    int n;
    cin >> n;
    thapHaNoi(n, 'A', 'B', 'C');
}
