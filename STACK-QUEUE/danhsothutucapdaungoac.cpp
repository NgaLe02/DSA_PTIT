#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int a[1000000];
void solve(string s)
{

    int cnt = 0, k = 0;
    // cout<<cnt<<" "<<k<<endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
            st.push(cnt);
            a[k++] = cnt;
            //     cout << a[k] << endl;
        }
        else if (s[i] == ')')
        {
            a[k++] = st.top();
            //     cout << a[k] << endl;
            st.pop();
        }
    }

    for (int i = 0; i < k; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        //  cout << s.size() << endl;
        solve(s);
    }
    return 0;
}