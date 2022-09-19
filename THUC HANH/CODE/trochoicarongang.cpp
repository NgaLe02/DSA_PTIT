#include <bits/stdc++.h>
using namespace std;
int n,ok;
char c,a[100];
void ktao(){
	ok = 1;
	for(int i = 1; i <= n; i++){
		a[i] = 'O';
	}
}
void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 'X'){
		a[i] = 'O';
		i--;
	}
	if(i==0) ok = 0;
	else a[i] = 'X';
}
bool check(){
	int dem1 = 0, dem2 = 0,res1=0,res2=0;
	for(int i = 1; i <= n; i++){
		if(a[i] == c){
			dem1 ++;
			dem2 = 0;
		}else{
			dem2++;
			dem1 = 0;
		}
		res1 = max(res1,dem1);
		res2 = max(res2,dem2);
	}
	if(res1 >= 5 && res1 > res2) return true;
	return false;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n>>c;
		ktao();
		while(ok){
			if(check()){
				for(int i = 1; i <= n; i++) cout << a[i];
				cout <<endl;
			}
			sinh();
		}
	}
}
