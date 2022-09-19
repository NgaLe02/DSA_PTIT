#include<bits/stdc++.h>
using namespace std;

long long n;
int s;
 
long long getSum(int a)
{
    long long sum = 0;
    while (a != 0) {
        sum = sum + a % 10;
        a = a / 10;
    }
    return sum;
}

long long smallestNumber(int s)
{
    long long i = n;
    while (1) {
        if (getSum(i) == s) {
        	return i;
        }
        i++;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		int m = n;
		cout << smallestNumber(s) - m<< endl;
	}
			return 0;
}
