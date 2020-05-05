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
		
		int n, k, p=0, l=1;
		cin >> n >> k;
		
		int v[n], a[n+2];
		
		memset(a, 0, sizeof a);
		
		for(int i=0; i<n; i++) cin >> v[i];
		
		for(int i=1; i<n-1; i++){
			if(v[i] > v[i-1] and v[i] > v[i+1]) a[i+1] = 1;
		}
		
		for(int i=1; i<=n+1; i++) a[i] += a[i-1];
		
		for(int i=1; i<=n-k+2; i++){
			if(p < a[i+k-2]-a[i]){p = a[i+k-2]-a[i]; l=i;}
		}
		
		cout << p+1 << ' ' << l << endl;
		
	}	
	
	      
	return 0;
}
