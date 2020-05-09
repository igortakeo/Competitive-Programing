#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
		int n;
		cin >> n;
		
		vector<int>ans;
		
		int vis[n+1];
		
		memset(vis, 0, sizeof vis);
		
		int mov[6] = {-4, -3, -2, 2, 3, 4};
		
		if(n <= 3){
			cout << -1 << endl; 
			return;
		}
	
		ans.push_back(n-1);
		vis[n-1] = 1;
		for(int i=0; i<n-1; i++){
			bool flag = false;
			int k = ans[i];
			for(int j=0; j<6; j++){
				if(k+mov[j] > 0 and k+mov[j] <= n and vis[k+mov[j]] == 0){
					ans.push_back(k+mov[j]);
					flag = true;
					vis[k+mov[j]] = 1;
					break;
				}
			}
			if(!flag){
				cout <<  -1 << endl;
				return;
			}		
		}
		
		for(auto a : ans) cout << a << ' ';
		cout << endl;
		
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--){
		 solve();	
	}
	      
	return 0;
}
	

