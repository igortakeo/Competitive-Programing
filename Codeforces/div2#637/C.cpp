#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
		
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		int v[n+1];
		int pos[n+1], vis[n+1];
		
		memset(vis, 0, sizeof vis);
		
		for(int i=1; i<=n; i++) cin >> v[i];
		
		for(int i=1; i<=n; i++) pos[v[i]] = i;	
		
		int r=-1;
		bool flag = true;
		for(int i=1; i<=n; i++){
		
			if(r == -1){
				vis[pos[i]] = 1;
				r = pos[i]+1;
			}
			else if(r == pos[i]){
				vis[pos[i]] = 1;
				r++;
			} 
			else{
				flag = false;
				break;
			}		
			if(r > n) r = -1;
			else if(vis[r]) r = -1;
		}
		
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
		
	}	
	
	      
	return 0;
}
