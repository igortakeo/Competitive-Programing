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
		int n, k;
		cin >> n >> k;
		
		int v[n], sum = 0;
		map<int, int>m;
		
		for(int i=0; i<n; i++) cin >> v[i];	
		
		for(int i=0; i<n/2; i++){		
			m[v[i]+v[n-i-1]]++;
		}
		
		int p[2*k+2];
		memset(p, 0, sizeof p);
			
		for(int i=0; i<n/2; i++){
			int a = 1+v[i], b = k+v[i], c = 1+v[n-1-i], d = k+v[n-1-i];
			p[min(a,c)]++;
			p[max(d,b) + 1]--;
		}
		
		for(int i=1; i<=2*k; i++) p[i] += p[i-1];
		
		int ans = 2e6;
		for(int i=2; i<=2*k; i++){
			ans = min(ans, (p[i] - m[i]) + (n-2*p[i]));
		}		
		cout << ans << endl;
		
	}	
	
	      
	return 0;
}
