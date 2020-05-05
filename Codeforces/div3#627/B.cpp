#include <bits/stdc++.h>
using namespace std;


int vis[5001];

int main(){

	int t;
	cin >> t;

	while(t--){
		
		int n, x;
		cin >> n;

		map<int, pair<int, int>>m;
		set<int>s;

		for(int i=0; i<n; i++){
			cin >> x;
			s.insert(x);
			if(vis[x] == 0){
				m[x].first = i;
				vis[x] = 1;
			}

			else m[x].second = i;
		}

		bool flag = false;
		for(auto it : s){

			if(m[it].second - m[it].first > 1){
				flag = true;
				break;
			}
		}

		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl; 

		memset(vis, 0, sizeof vis);

	}


	return 0;
}