#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100005],max=0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int l = i-1, r = i+1,dem=1;
		while(l){
			if(a[i] > a[l]) break;
			dem++; l--;
		}
		while(r<=n){
			if(a[i] > a[r]) break;
			dem++; r++;
		}
		if(dem*a[i] > max) max = dem*a[i];
	}
	cout <<max<<endl;
	return 0;
}

