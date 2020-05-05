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
		
		for(int i=0; i<n; i++) cin >> a[i];
		
		int u[27][n+1];
		memset(u, 0, sizeof u);
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=26; j++){
				if(a[i-1] == j) u[j][i] = u[j][i-1]+1;	
				else u[j][i] = u[j][i-1];
			}
		}
		
		int out=0, in=0, ans=0;
			
		for(int l=1; l<=n; l++){
			for(int r=l; r<=n; r++){
				out = 0; in = 0;
				for(int k=1; k<=26; k++){
					in = max(in, u[k][r] - u[k][l-1]);
					out = max(out, min(u[k][l-1], u[k][n]-u[k][r])*2);
				}
				ans = max(ans, out+in);
			}
		}
		
		cout << ans << endl;
			
	}


	return 0;
}
