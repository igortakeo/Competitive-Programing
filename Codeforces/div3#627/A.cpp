#include <bits/stdc++.h>
#define MAX 101
using namespace std;


int vis[MAX];

int main(){

	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;

		int v[n];
		vector<int>s;

		for(int i=0; i<n; i++) cin >> v[i];

		for(int i=0; i<n; i++){
			if(vis[v[i]] == 0){
				s.push_back(v[i]);
				vis[v[i]] = 1;
			}
		}


		bool flag = true;
		int diff, x;
		for(int i=0; i<s.size(); i++){
			x = s[i];
			for(int j=0; j<s.size(); j++){
				diff = abs(x- s[j]);
				if(diff%2 != 0){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}	

		if(!flag) cout << "NO" << endl;
		else cout << "YES" << endl;


		memset(vis, 0, sizeof vis);
	}


	return 0;
}