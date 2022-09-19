#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x = "1238004765";
    swap(x[1], x[4]);
    swap(x[4], x[2]);
    swap(x[4], x[6]);
    swap(x[4], x[9]);
    swap(x[4], x[8]);
    cout << x << endl;
}