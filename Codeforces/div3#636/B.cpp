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
		
		int n, even=2, odd=1;
		cin >> n;
		
		int ans[n], sume=0, sumo=0;
		
		for(int i=0; i<n/2; i++){
			ans[i] = even;
			even+=2;	
			sume += ans[i];
		}
		
		for(int i=n/2; i<n-1; i++){
			ans[i] = odd;
			odd+=2;
			sumo += ans[i];	
		}
		
		if((sume-sumo) % 2 == 0) cout << "NO" << endl;
		else{
			ans[n-1] = sume-sumo; 
			cout << "YES" << endl;
			for(int i=0; i<n; i++) cout << ans[i] << ' ';
			cout << endl;	
		}
		
		
	}	
		
	      
	return 0;
}
