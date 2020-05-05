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
		ll a, b, q;
		cin >> a >> b >> q;
		
		ll lcm = (a*b)/__gcd(a,b);
		
		ll sum[lcm], m;
		memset(sum, 0, sizeof sum);
		
		for(int i=1; i<lcm; i++){
			if((i%a)%b != (i%b)%a)sum[i]++;
		}
		for(int i=1; i<lcm; i++) sum[i] += sum[i-1];
		m = sum[lcm-1];
		
		while(q--){
			ll l, r;
			cin >> l >> r;
			cout << (sum[r%lcm]+(r/lcm)*m) - (sum[(l-1)%lcm]+((l-1)/lcm)*m) << ' ';	
		}
		cout << endl;
		
		
	}
		
	      
	return 0;
}
