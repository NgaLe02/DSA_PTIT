#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,maxx=0,dem=0,a[100005],res=0; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == maxx){
			dem++;
			res = max(res,dem);
		}else{
			dem = 0;
		}
	}
	cout <<res<<endl;
}
