#include <bits/stdc++.h>
using namespace std;

// con ếch có thể nhảy 1, 2, hoặc 3 bước.
// vì thế nếu con ếch đang ở bậc thứ i, thì
// tiếp theo nó có thể ở bậc thứ i-1, i-2, i-3
// hay nói cách khác. Nếu hiện tại con ếch ở bậc thứ i,
// nó đã nhảy từ bậc i-3, i-2 hoặc i-1.

int count(int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else
        return count(n - 3) + count(n - 2) + count(n - 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}