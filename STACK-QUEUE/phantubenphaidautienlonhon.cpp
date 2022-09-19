#include <bits/stdc++.h>
/* Phần tử bên phải đầu tiên lớn hơn:
 4 5 2 25
 -> m[3]=-1;  Stack: 25;
 -> 2<25   ;  m[2]=25  ; Stack: 2 25;
 -> 5>2 bỏ 2; m[1]=25  ; Stack:5 25
 -> 4<5 ; m[0]=5 ; 


*/
using namespace std;

void xuly(int a[], int n)
{
    stack<int> st;
    int m[n], i;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[i] >= st.top())
            st.pop();
        if (st.empty())
            m[i] = -1;
        else
        {
            m[i] = st.top();
        }
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << m[i] << " ";
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
        {
            cin >> a[i];
        }
        xuly(a, n);
    }
}
