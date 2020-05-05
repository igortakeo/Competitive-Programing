#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;


int main(){

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<pii>v;
		
		int x, y;
		for(int i=0; i<n; i++){
			cin >> x >> y;
			v.push_back({x, y});
		}
		
		sort(v.begin(), v.end());
		
		string ans = "";
		bool flag = true;
		
		int i=0, j=0;	
		for(auto a : v){
			int u, r;
			u = a.second-j;
			r = a.first-i;
		
			if(u < 0 or r < 0){flag = false; break;}
			
			for(int i=0; i<r; i++) ans+='R';
			for(int i=0; i<u; i++) ans+='U';
			i += r;
			j += u;
		}
		
		if(flag){
			cout << "YES" << endl;
			cout << ans << endl;
		}
		else{
			cout << "NO" << endl;
		}

		
	}
		
	
	return 0;
}
