#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	
	int n, m;
	cin >> n >> m;
	
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	if(n == 2){
		cout << m << endl;
		return;
	}
		
		
	cout << m*2 << endl;	
		
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
