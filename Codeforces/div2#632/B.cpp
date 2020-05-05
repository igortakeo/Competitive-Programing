#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		int a[n], b[n];	
		bool nt= false, pt = false, flag = true;
		
		for(int i=0; i<n; i++) cin >> a[i];
		for(int i=0; i<n; i++) cin >> b[i];
		
		for(int i=0; i<n; i++){
			
			if(a[i] > b[i] and !nt){flag = false; break;}
			else if(a[i] < b[i] and !pt){flag = false; break;}
			
			if(a[i] > 0) pt = true;
			else if(a[i] < 0) nt = true;	
			
			
		}
		
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	
	return 0;
}
