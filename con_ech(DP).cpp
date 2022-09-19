#include <bits/stdc++.h>
using namespace std;

// con ếch có thể nhảy 1, 2, hoặc 3 bước.
// vì thế nếu con ếch đang ở bậc thứ i, thì
// tiếp theo nó có thể ở bậc thứ i-1, i-2, i-3
// hay nói cách khác. Nếu hiện tại con ếch ở bậc thứ i,
// nó đã nhảy từ bậc i-3, i-2 hoặc i-1.
long long count(int n)
{
    long long cnt[n + 1];
    cnt[0] = 1;
    cnt[1] = 1;
    cnt[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i - 2] + cnt[i - 3];
    }
    return cnt[n];
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