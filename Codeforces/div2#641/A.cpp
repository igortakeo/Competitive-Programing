#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int divisor(int n){
	
	set<int>v;
	for(int i=1; i*i <= n; i++){
		if(n%i == 0){
			v.insert(i);		
			if(i != (n/i))v.insert(n/i);
		}
	}
	auto it = v.begin();
	it++;
	return *it;
}

void solve(){
	int n, k;
	cin >> n >> k;	
	int s = divisor(n);
	cout << n+s+2*(k-1) << endl;
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
