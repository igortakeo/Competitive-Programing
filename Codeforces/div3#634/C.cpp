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
		
		vector<int>v(n);
		int freq[n+1]; 
		int d=0, ig=0;
		
		memset(freq, 0, sizeof freq);
		
		for(int i=0; i<n; i++) cin >> v[i];
		
		for(int i=0; i<n; i++){
			freq[v[i]]++;
			if(freq[v[i]] == 1)d++;
		}
		
		for(int i=0; i<=n; i++) ig = max(ig, freq[i]); 
		
		if(n == 1) cout << 0 << endl; 
		else if(ig == 0 or d == 1) cout << 1 << endl;
		else{
			if(d < ig) cout << d << endl;
			else if(d == ig) cout << d-1 << endl;
			else cout << ig << endl;
		}
	
	}
	
	
	
	
	return 0;
}

