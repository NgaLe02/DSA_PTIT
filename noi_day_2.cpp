#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define tmp 1000000007;

ll cost(int a[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    int cost = 0;
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost = (cost + (first + second) % 1000000007) % tmp;
        pq.push((first + second) % 1000000007);
    }
    return cost;
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
        for (int &x : a)
            cin >> x;
        cout << cost(a, n) << endl;
    }
}