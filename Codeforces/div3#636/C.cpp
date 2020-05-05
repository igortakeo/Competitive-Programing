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
		
		int m;
		cin >> m;
		int a[m];
		
		for(int i=0; i<m; i++) cin >> a[i];
		
		int p=0, n=-1000000001;
		ll sum=0;
		bool flagp = false, flagn = false;
		for(int i=0; i<m; i++){
			if(a[i] >= 0){
				flagp = true;
				p = max(p, a[i]);
				if(flagn){
					sum+=n;
					n=-1000000001;
					flagn= false;
				}
			}
			else{
				flagn = true;
				n = max(n, a[i]);
				if(flagp){
					sum += p;
					p=0;
					flagp = false;
				}
			}
		}
		
		if(flagn) sum+=n;
		if(flagp) sum+=p;
			
		cout << sum << endl;
		
	}

	
	      
	return 0;
}
