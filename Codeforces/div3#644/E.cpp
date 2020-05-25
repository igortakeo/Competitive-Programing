#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
	int n;
	cin >> n;
	
	char m[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> m[i][j];	
	}
	
	bool flag = true;
	for(int i=0; i<n; i++){	
		for(int j=0; j<n; j++){
			if(m[i][j] == '1' and( i == n-1 or j == n-1) ) continue;
			
			if(m[i][j] == '1'){
				if(m[i+1][j] != '1' and m[i][j+1] != '1') flag = false;
			}
		}
	}
	
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
