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
		
		ll x, y, a, b, ans=0;
		cin >> x >> y;
		cin >> a >> b;
		
		ans = abs(x-y)*a;
		x = min(x,y);
		
		cout << min(ans+b*x, ans+2*a*x) << endl;
		
	}	
	
	return 0;
}
