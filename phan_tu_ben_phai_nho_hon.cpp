#include <bits/stdc++.h>
using namespace std;

void nextGreater(int a[], int b[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            b[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        b[st.top()] = -1;
        st.pop();
    }
    // for (int i = 0; i < n; i++)
    //     cout << b[i] << " ";
    // cout << endl;
}

void rightSmaller(int a[], int b[], int n)
{
    stack<int> st;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i] && i > st.top())
        {
            c[b[st.top()]] = a[i];
            st.pop();
        }
        st.push(b[i]);
    }
    while (!st.empty())
    {
        c[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        nextGreater(a, b, n);
        rightSmaller(a, b, n);
    }
    return 0;
}