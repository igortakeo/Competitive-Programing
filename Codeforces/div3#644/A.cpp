#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
	int a, b;
	cin >> a >> b;
	int c = max(a, b);
	int d = min(a, b);
	int area = (2*d)*c;
	
	for(int i=1; i<=5000; i++){
		if(i*i >= area and i >=2*d and i>= c){
			cout << i*i << endl;
			return;
		}
	}
		
}	

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	

