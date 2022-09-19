#include<bits/stdc++.h>
using namespace std;

int MOD=(int)1e9+7;

long long binPow(long long a,long long b){
	if(b==0) return 1;
	long long x=binPow(a,b/2);
	if(b%2==1){
		return (x*x%MOD)*(a%MOD)%MOD;
	}
	else return (x%MOD)*(x%MOD)%MOD;
}

int main(){
	int t;
	cin >>t;
	while(t--){
		long long n;
		int k;
		cin >>n>>k;
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=binPow(i,k);
		}
		cout <<sum<<endl;
	}
}