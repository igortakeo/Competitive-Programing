#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
	int n;
	cin >> n;
	
	int v[n];
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	int even=0, odd=0;
	
	for(int i=0;i<n; i++){
		if(v[i]%2 == 0) even++;
		else odd++;
	}
	
	if(even%2 == 0 and odd%2 == 0){
		cout << "YES" << endl;
		return;
	}
	
	
	sort(v, v+n);
	for(int i=0; i<n-1; i++){
		int diff = v[i+1]-v[i]; 
		if(diff == 1){
			even--; odd--;		
			if(even%2 == 0 and odd%2 == 0){
				cout << "YES" << endl;
				return;
			}				
			i++;
		}
		
	}
	
	cout << "NO" << endl;
	
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
	
