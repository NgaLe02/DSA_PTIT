#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n)
{
    stack<int> st1, st2; //lưu chỉ số
    int m[n], b[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st1.empty() && a[i] >= a[st1.top()])
        {
            st1.pop();
        }
        if (st1.empty())
            m[i] = -1;
        else
            m[i] = st1.top(); // lưu chỉ số
        st1.push(i);
        if (m[i] == -1)
            b[i] = -1;
        else
        {
            while (!st2.empty() && m[i] >= st2.top())
                st2.pop();
            while (!st2.empty() && a[m[i]] <= a[st2.top()])
            {
                st2.pop();
            }

            if (st2.empty())
                b[i] = -1;
            else
                b[i] = a[st2.top()];
        }
        st2.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve(a, n);
    }
    return 0;
}