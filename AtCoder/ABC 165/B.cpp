#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	ll x, y = 100;
	int ans = 0;
	
	cin >> x;	
	
	while(y < x){
		ans++;
		y = y + y*0.01;
	}
	
	cout << ans << endl;
	      
	return 0;
}

