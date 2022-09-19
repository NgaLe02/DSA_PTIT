#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,n;
	cin>>t;
	while(t--){
		cin >> n;
		long long  a[n],right[n],left[n],maxi=0;
		for (int i =0 ; i < n;++i) cin >> a[i];
		stack <long long > st;
		for(int i = 0 ; i < n;++i) {
            while(!st.empty()&&a[i]<a[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            right[st.top()] = n ;
            st.pop();
        }
        for(int i = n -1; i>=0;--i) {
            while(!st.empty()&&a[i]<a[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }
        for(int i = 0  ; i < n ;++i) maxi = max (maxi , a[i]*(right[i]-left[i]-1));
        cout << maxi << endl;
	}
}
