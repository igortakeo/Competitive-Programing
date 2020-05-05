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
		
		vector<int>a(n);
		vector<int>v[201];
		
		for(int i=0; i<n; i++) cin >> a[i];
		
		int u[201][n+1];
		memset(u, 0, sizeof u);
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=200; j++){
				if(a[i-1] == j) u[j][i] = u[j][i-1]+1;	
				else u[j][i] = u[j][i-1];
			}
			v[a[i-1]].push_back(i);
		}
				
		int ans=0; 
		
		for(int k = 1; k<=200; k++){
			int middle = v[k].size()/2;	
			for(int i=0; i < middle; i++){
				int l = v[k][i]; 	
				int r = v[k][v[k].size()-1-i];
				int in = 0;

				for(int j = 1; j <= 200; j++){
					in = max(in, u[j][r-1]-u[j][l]);		
				}

				ans = max(ans, (i+1)*2 + in);
			}
		
			ans = max(ans, (int)v[k].size());
		}
		
		cout << ans << endl;
			
	}
	
	
	      
	return 0;
}
