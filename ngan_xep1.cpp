#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	stack<int>st;
	string s;
	while(cin >> s) {
		if(s == "push") {
			int n;
			cin >> n;
			st.push(n);
		}
		else if(s == "pop") {
			st.pop();
		}
		else if(s == "show") {
			if(st.empty()) cout << "empty\n";
			else {
			vector<int>luu;
			while(!st.empty()) {
				luu.push_back(st.top());
				st.pop();
			}
			for(int i = luu.size() - 1; i >= 0; i--) {
				cout << luu[i] << " ";
				st.push(luu[i]);
			}
			cout << endl;
		    }
		}
	}
}
