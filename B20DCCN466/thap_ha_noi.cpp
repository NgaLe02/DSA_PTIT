#include <bits/stdc++.h>
using namespace std;

void chuyen(char a, char b)
{
    cout << a << " -> " << b << endl;
}
void thapHaNoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        chuyen(a, c);
        return;
    }
    thapHaNoi(n - 1, a, c, b);
    chuyen(a, c);
    thapHaNoi(n - 1, b, a, c);
}
int main()
{
    int n;
    cin >> n;
    thapHaNoi(n, 'A', 'B', 'C');
    return 0;
}